package com.jorkyin.barley.util;

/**
 * Created by yinjian on 2018/2/26.
 */

public class P2PParam {

    /**
     * mUID : PPRT-012345-XXXXXX
     * nUser : admin
     * mPassword : admin
     */
    private String mCamName=null;
    private String mUID=null;
    private String mUser=null;
    private String mPassword=null;
    private String mIP=null;
    private String mStateString =null;
    private int mStateValue =-1;
    private String mMac=null;
    private int mPort=0;

    public P2PParam(String name ,String UID,String IPAddr,String Mac,int port, String user, String password) {
        this.mCamName = name;
        this.mUID = UID;
        this.mIP=IPAddr;
        this.mMac=Mac;
        this.mPort=port;
        this.mUser = user;
        this.mPassword = password;
    }

    public P2PParam(String name ,String UID, String user, String password) {
        this.mCamName = name;
        this.mUID = UID;
        this.mUser = user;
        this.mPassword = password;
    }

    public String getUID() {
        return mUID;
    }

    public void setUID(String UID) {
        this.mUID = UID;
    }

    public String getUser() {
        return mUser;
    }

    public void setUser(String user) {
        this.mUser = user;
    }

    public String getPassword() {
        return mPassword;
    }

    public void setPassword(String password) {
        this.mPassword = password;
    }


    public String getIP() {
        return mIP;
    }

    public void setIP(String IP) {
        this.mIP = IP;
    }

    public String getStateString() {
       return mStateString;
    }

    public void setStateString(String state) {
        this.mStateString = state;
    }

    public int getStateValue() {
        return mStateValue;
    }

    public void setStateValue(int mStateValue) {
        this.mStateValue = mStateValue;
    }

    public String getCamName() {
        return mCamName;
    }

    public void setCaName(String camName) {
        this.mCamName = camName;
    }

    public String getMac() {
        return mMac;
    }

    public void setMac(String mMac) {
        this.mMac = mMac;
    }

    public int getPort() {
        return mPort;
    }

    public void setPort(int mPort) {
        this.mPort = mPort;
    }


}
