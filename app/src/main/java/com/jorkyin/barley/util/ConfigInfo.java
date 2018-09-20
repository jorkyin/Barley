package com.jorkyin.barley.util;

/**
 * Created by yinjian on 2018/2/3.
 */

public class ConfigInfo {
    private String mUID;
    private String mName;
    private String mActivity;

    public ConfigInfo(String UID, String name, String activity) {
        this.mUID = UID;
        this.mName = name;
        this.mActivity = activity;
    }

    public String getName() {
        return mName;
    }

    public void setName(String name) {
        this.mName = name;
    }

    public String getActivity() {
        return mActivity;
    }

    public void setActivity(String activity) {
        this.mActivity = activity;
    }


    public String getUID() {
        return mUID;
    }

    public void setUID(String UID) {
        this.mUID =UID;
    }
}
