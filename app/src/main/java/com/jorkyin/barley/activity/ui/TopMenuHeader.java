package com.jorkyin.barley.activity.ui;

import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.jorkyin.barley.R;

public class TopMenuHeader {
    // 顶部菜单左边按钮
    public ImageView topMenuLeft;

    // 顶部菜单右边按钮
    public ImageView topMenuRight;

    // 顶部菜单文字
    public TextView topMenuTitle;

    TopMenuHeader(View v) {
        // 顶部中间文字
        topMenuTitle = v.findViewById(R.id.top_menu_title);

        // 左边按钮
        topMenuLeft=v.findViewById(R.id.top_menu_left);

        // 右边按钮
        topMenuRight=v.findViewById(R.id.top_menu_right);

    }
}
