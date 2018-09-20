package com.jorkyin.barley.activity.ui;

import android.app.Activity;
import android.content.Intent;
import android.graphics.SurfaceTexture;
import android.os.Bundle;
import android.support.constraint.ConstraintLayout;
import android.util.Log;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.TextureView;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.google.gson.Gson;
import com.jorkyin.barley.R;
import com.jorkyin.barley.activity.presenter.LivePresenter;
import com.jorkyin.barley.util.Const;
import com.jorkyin.barley.util.P2PParam;

import butterknife.BindView;
import butterknife.ButterKnife;
import butterknife.OnClick;


public class LiveActivity extends Activity implements TextureView.SurfaceTextureListener {

    private static final String TAG = "LiveActivity";
    @BindView(R.id.video_texture)
    TextureView mVideoTextureView;//视频显示
    @BindView(R.id.control_constraint)
    ConstraintLayout mControlConstraintLayout;//视频播放控制栏
    @BindView(R.id.btn_voice)
    ImageView mBtnVoiceImageView;//音频开关
    @BindView(R.id.btn_resolution)
    TextView mBtnResolution;//分辨率
    @BindView(R.id.rec_status)
    ImageView mRecStatus;//录像状态
    @BindView(R.id.btn_video_enlarge)
    ImageView mBtnVideoEnlarge;//全屏开关

    TopMenuHeader mTopMenuHeader;//标题栏
    private P2PParam mP2PParam;
    private Surface mSurface;
    private LivePresenter presenter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_live);
        ButterKnife.bind(this);
        //获取MainActivity传递过来的P2Pjson参数,并且解析
        mP2PParam = new Gson().fromJson(getIntent().getStringExtra(Const.P2PPARAM), P2PParam.class);
        presenter = new LivePresenter();
        mVideoTextureView.setSurfaceTextureListener(this);


        initActivity();
    }

    @Override
    protected void onStart() {
        super.onStart();

        presenter.onStart(mP2PParam);
    }

    private void initActivity() {
        if (mTopMenuHeader==null){//初始化标题栏
            mTopMenuHeader = new TopMenuHeader(findViewById(R.id.title_layout));
            initTopMenuTitle();
        }
    }

    //初始化标题栏
    private void initTopMenuTitle() {
        mTopMenuHeader.topMenuTitle.setText("厨房");
        mTopMenuHeader.topMenuLeft.setVisibility(View.VISIBLE);
        mTopMenuHeader.topMenuLeft.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.i(TAG, "onClickButton: TopMenuHeader Left menu = ");
            }
        });

        mTopMenuHeader.topMenuRight.setVisibility(View.VISIBLE);
        mTopMenuHeader.topMenuRight.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(LiveActivity.this, ConfigActivity.class));
            }
        });
    }
    @OnClick({R.id.btn_voice, R.id.btn_resolution, R.id.btn_video_enlarge,
            R.id.control_constraint,R.id.btn_photo,R.id.btn_rec})
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.btn_voice:
                break;
            case R.id.btn_resolution:
                break;
            case R.id.btn_video_enlarge:
                Log.i(TAG, "onClick: 全屏");
                break;
            case R.id.control_constraint:
                break;
            case R.id.btn_photo:
                break;
            case R.id.btn_rec:
                break;
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
    }
    // SurfaceTexture准备就绪
    @Override
    public void onSurfaceTextureAvailable(SurfaceTexture surfaceTexture, int i, int i1) {
        presenter.player(surfaceTexture);
    }
    // SurfaceTexture缓冲大小变化
    @Override
    public void onSurfaceTextureSizeChanged(SurfaceTexture surfaceTexture, int i, int i1) {

    }
    // SurfaceTexture即将被销毁
    @Override
    public boolean onSurfaceTextureDestroyed(SurfaceTexture surfaceTexture) {
        return false;
    }
    // SurfaceTexture通过updateImage更新
    @Override
    public void onSurfaceTextureUpdated(SurfaceTexture surfaceTexture) {

    }
}
