package com.jorkyin.barley.activity.ui;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.jorkyin.barley.R;
import com.jorkyin.barley.base.OnClickItemViewListener;
import com.jorkyin.barley.util.ConfigInfo;
import com.jorkyin.barley.util.RecyclerItemDecoration;

import java.util.ArrayList;

public class ConfigActivity extends AppCompatActivity {
    private ArrayList<ConfigInfo> mConfigInfoList = new ArrayList<>();
    private RecyclerView mConfigRectyclerView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_config);

        mConfigRectyclerView = findViewById(R.id.config_recycler_view);

        setDate();
        showView();
    }

    private void showView() {
        RecyclerView.LayoutManager layoutManager = new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false);
        ConfigRecyclerAdpter adpter = new ConfigRecyclerAdpter(mConfigInfoList);
        mConfigRectyclerView.setLayoutManager(layoutManager);
        mConfigRectyclerView.addItemDecoration(new RecyclerItemDecoration(this, LinearLayoutManager.VERTICAL));
        mConfigRectyclerView.setAdapter(adpter);
    }

    private void setDate() {
        for (int i = 0; i < 10; i++) {
            mConfigInfoList.add(new ConfigInfo("uid", "asdfsdf", "AAAAAAA.class"));
        }

    }


    class ConfigRecyclerAdpter extends RecyclerView.Adapter<ConfigRecyclerAdpter.ViewHolder> {
        private ArrayList<ConfigInfo> mData = new ArrayList<>();
        private OnClickItemViewListener mOnClickItemViewListener;

        ConfigRecyclerAdpter(ArrayList<ConfigInfo> data) {
            this.mData = data;
        }

        public void update(ArrayList<ConfigInfo> data) {
            this.mData = data;
            notifyDataSetChanged();
        }

        @Override
        public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_config, parent, false);
            return new ViewHolder(view);
        }

        @Override
        public void onBindViewHolder(ViewHolder holder, final int position) {
            View.OnClickListener onClickListener = new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    mOnClickItemViewListener.onRecyclerViewItemClick(view, position);
                }
            };

            holder.item_config_name.setText(mData.get(position).getName());

        }

        @Override
        public int getItemCount() {
            return mData == null ? 0 : mData.size();
        }


        class ViewHolder extends RecyclerView.ViewHolder {
            TextView item_config_name;

            ViewHolder(View itemView) {
                super(itemView);
                item_config_name = itemView.findViewById(R.id.item_config_name);
            }
        }

        //设置接口回调
        void setOnClickItemViewListener(OnClickItemViewListener onClickItemViewListener) {
            mOnClickItemViewListener = onClickItemViewListener;
        }
    }
}
