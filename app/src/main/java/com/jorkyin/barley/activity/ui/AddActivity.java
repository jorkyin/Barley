package com.jorkyin.barley.activity.ui;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.google.zxing.integration.android.IntentIntegrator;
import com.google.zxing.integration.android.IntentResult;
import com.jorkyin.barley.R;
import com.jorkyin.barley.util.Const;

public class AddActivity extends AppCompatActivity implements View.OnClickListener {

    private static final String TAG = "AddActivity";
    private EditText mName;
    private EditText mUID;
    private EditText mUser;
    private EditText mPassword;
    TopMenuHeader mTopMenuHeader;//标题栏
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_camera_add);

        mName = findViewById(R.id.camera_add_name_et);
        mUID = findViewById(R.id.camera_add_uid_et);
        mUser = findViewById(R.id.camera_add_user_et);
        mPassword = findViewById(R.id.camera_add_password_et);

        findViewById(R.id.camera_add_Search).setOnClickListener(this);
        findViewById(R.id.camera_add_enter).setOnClickListener(this);
        findViewById(R.id.camera_add_scan).setOnClickListener(this);
        initActivity();
    }
    private void initActivity() {
        if (mTopMenuHeader==null){//初始化标题栏
            mTopMenuHeader = new TopMenuHeader(findViewById(R.id.title_layout));
            initTopMenuTitle();
        }
    }
    //初始化标题栏
    private void initTopMenuTitle() {
        mTopMenuHeader.topMenuTitle.setText("添加摄像机");
        mTopMenuHeader.topMenuLeft.setVisibility(View.VISIBLE);
        mTopMenuHeader.topMenuLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });
    }
    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.camera_add_enter:
                if (mName.getText() == null) {
                    Toast.makeText(this, "摄像机名称不能为空", Toast.LENGTH_LONG).show();
                    break;
                } else if (mUID.getText() == null) {
                    Toast.makeText(this, "UID不能为空", Toast.LENGTH_LONG).show();
                    break;
                } else if (mUser.getText() == null) {
                    Toast.makeText(this, "用户不能为空", Toast.LENGTH_LONG).show();
                    break;
                } else if (mPassword.getText() == null) {
                    Toast.makeText(this, "密码不能为空", Toast.LENGTH_LONG).show();
                    break;
                } else {
                    Intent intentTemp = new Intent();
                    intentTemp.putExtra(Const.NAME, mName.getText().toString());
                    intentTemp.putExtra(Const.UID, mUID.getText().toString());
                    intentTemp.putExtra(Const.USER, mUser.getText().toString());
                    intentTemp.putExtra(Const.PASSWORD, mPassword.getText().toString());
                    setResult(Const.MAINACTIVITY_AADACTIVITY_TITLE, intentTemp);
                    finish();
                }
                break;
            case R.id.camera_add_scan:
                new IntentIntegrator(this)
                        .setOrientationLocked(false)
                        .setCaptureActivity(ScanActivity.class) // 设置自定义的activity是ScanActivity
                        .initiateScan(); // 初始化扫描
                break;
            case R.id.camera_add_Search:
                Log.i(TAG, "onClick: camera_add_Search");
                Intent S_intent = new Intent(AddActivity.this, SearchActivity.class);
                S_intent.putExtra(Const.DATALIST, getIntent().getStringExtra(Const.DATALIST));
                startActivityForResult(S_intent, Const.AADACTIVITY_SEARCHACTIVITY_TITLE);
                break;
        }
    }

    //回调获取扫描得到的条码值
    @Override
    // 通过 onActivityResult的方法获取扫描回来的值
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (data != null) {
            if (requestCode == Const.AADACTIVITY_SEARCHACTIVITY_TITLE) {
                super.onActivityResult(requestCode, resultCode, data);
                mUID.setText(data.getStringExtra(Const.UID));
            } else {
                IntentResult result = IntentIntegrator.parseActivityResult(requestCode, resultCode, data);
                if (result != null && result.getContents() != null) {
                    mUID.setText(result.getContents());
                }
            }
        }
    }
}
