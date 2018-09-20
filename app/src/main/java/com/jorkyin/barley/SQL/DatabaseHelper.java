package com.jorkyin.barley.SQL;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

import com.jorkyin.barley.util.Const;
import com.jorkyin.barley.util.P2PParam;

import java.util.ArrayList;


/**
 * Created by yinjian on 2018/1/31.
 */

public class DatabaseHelper extends SQLiteOpenHelper {
    private static final String TAG = "DatabaseHelper";

    public DatabaseHelper(Context context) {
        super(context, Const.DATABASE_NAME, null, Const.DATABASE_VERSION);
    }


    // 当第一次创建数据库的时候，调用该方法
    @Override
    public void onCreate(SQLiteDatabase db) {
        String sql = "create table " + Const.DATABASE_TABLE_NAME + "(" + Const.NAME + " varchar(20)," + Const.UID + " varchar(20)," + Const.USER + " varchar(20)," + Const.PASSWORD + " varchar(20))";
        //输出创建数据库的日志信息
        Log.i(TAG, "create Database------------->");
        //execSQL函数用于执行SQL语句
        db.execSQL(sql);
    }

    //当更新数据库的时候执行该方法
    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
    //输出更新数据库的日志信息
        Log.i(TAG, "update Database------------->");
    }

    public ArrayList<P2PParam> getCamInfo(){
        ArrayList<P2PParam> data=new ArrayList<>();
        //数据库
        //DatabaseHelper DBHelper = new DatabaseHelper(this);
        //得到一个可写的数据库
        SQLiteDatabase db = getReadableDatabase();
        Cursor cursor = db.query(Const.DATABASE_TABLE_NAME, null, null, null, null, null, null);
        if (cursor.moveToFirst()) {
            for (int i = 0; i < cursor.getCount(); i++) {
                cursor.move(i);
                data.add(new P2PParam(cursor.getString(0),//获得摄像机名称
                        cursor.getString(1),//获得ID
                        cursor.getString(2), //获得用户名
                        cursor.getString(3)//获得密码
                ));
            }
        }

        //关闭数据库
        db.close();
        return data;
    }

    public void addCamInfo(P2PParam CamInfo){
        //得到一个可读的SQLiteDatabase对象
        SQLiteDatabase db = getWritableDatabase();
        //生成ContentValues对象 //key:列名，value:想插入的值
        ContentValues cv = new ContentValues();
        //往ContentValues对象存放数据，键-值对模式
        cv.put(Const.NAME, CamInfo.getCamName());
        cv.put(Const.UID, CamInfo.getUID());
        cv.put(Const.USER, CamInfo.getUser());
        cv.put(Const.PASSWORD, CamInfo.getPassword());
        //调用insert方法，将数据插入数据库
        db.insert(Const.DATABASE_TABLE_NAME, null, cv);
        //关闭数据库
        db.close();
    }
}

