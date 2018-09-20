package com.jorkyin.barley.activity.ui;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.widget.TextView;

import com.google.gson.Gson;
import com.jorkyin.barley.R;
import com.jorkyin.barley.model.NativeCaller;
import com.jorkyin.barley.util.Const;
import com.jorkyin.barley.util.P2PParam;

import org.greenrobot.eventbus.EventBus;
import org.greenrobot.eventbus.Subscribe;
import org.greenrobot.eventbus.ThreadMode;


public class LiveActivity extends Activity implements SurfaceHolder.Callback {
    private static final String TAG = "LiveActivity";
    private SurfaceHolder mSurfaceHolder;
    private SurfaceView mSurfaceView;
    private P2PParam mP2PParam;
    private TextView live_state;
    private TextView networkSpeed;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_live);

        //获取MainActivity传递过来的P2P参数
        Intent intent = getIntent();
        String jsonData = intent.getStringExtra(Const.P2PPARAM);
        mP2PParam = new Gson().fromJson(jsonData, P2PParam.class);

        mSurfaceView = findViewById(R.id.live_surfacView);
        mSurfaceHolder = mSurfaceView.getHolder();
        mSurfaceHolder.addCallback(this);

        live_state = findViewById(R.id.live_state);
        networkSpeed = findViewById(R.id.live_networkSpeed);

        //注册订阅者,用于C回调Java的方法，更新UI
        EventBus.getDefault().register(this);

      /*  new Thread(new Runnable() {
            @Override
            public void run() {

                nativeJava2C.ConnectDevStart(mP2PParam.getUID(), mP2PParam.getUser(), mP2PParam.getPassword());
                nativeJava2C.liveVideoStart(mSurfaceHolder.getSurface());
            }
        }).start();*/
    }

    //定义处理接收的方法，更新UI
    @Subscribe(threadMode = ThreadMode.MAIN)
    public void userEventBus(P2PParam p2PParam) {

        live_state.setText(p2PParam.getState());

        if (p2PParam.getState().equals("on line")){

            new Thread(new Runnable() {
                @Override
                public void run() {

                    Log.e(TAG, "liveVideoStart" );
                  // NativeCaller.liveVideoStart(mSurfaceHolder.getSurface());
                }
            }).start();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        Log.e(TAG, "onStart ConnectDevStart");
       // NativeCaller.ConnectDevStart(mP2PParam.getUID(), mP2PParam.getUser(), mP2PParam.getPassword());
    }

    @Override
    protected void onPause() {
        super.onPause();
        Log.e(TAG, "onPause liveVideoStop" );
       // NativeCaller.liveVideoStop();
        Log.e(TAG, "onPause ConnectDevStop" );
      //  NativeCaller.ConnectDevStop();

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        //注销注册
        EventBus.getDefault().unregister(this);
    }

    @Override
    public void surfaceCreated(SurfaceHolder surfaceHolder) {

    }

    @Override
    public void surfaceChanged(SurfaceHolder surfaceHolder, int i, int i1, int i2) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder surfaceHolder) {

    }
}
