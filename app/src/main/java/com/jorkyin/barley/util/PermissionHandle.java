package com.jorkyin.barley.util;

import android.Manifest;
import android.app.Activity;
import android.content.Context;

import pub.devrel.easypermissions.EasyPermissions;

/**
 * Created by yinjian on 2018/1/26.
 */

public class PermissionHandle {
    private static final int num = 123;//用于验证获取的权
    public static void requireSomePermission(Context context) {
       String[] perms = {
               // 把你想要申请的权限放进这里就行，注意用逗号隔开
               Manifest.permission.WRITE_EXTERNAL_STORAGE,
               Manifest.permission.READ_EXTERNAL_STORAGE,
               Manifest.permission.MODIFY_AUDIO_SETTINGS,
               Manifest.permission.RECORD_AUDIO,
               Manifest.permission.INTERNET,
               Manifest.permission.CAMERA};

       if (EasyPermissions.hasPermissions(context, perms)) {
           // Already have permission, do the thing
           //Toast.makeText(this, "Permissions Granted!" + Arrays.toString(perms), Toast.LENGTH_LONG).show();
       } else {
           // Do not have permissions, request them now
           EasyPermissions.requestPermissions((Activity) context, "获取权限", num, perms);
       }
    }
}
