package com.jorkyin.barley.activity.RecyclerAdapter;

import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.jorkyin.barley.R;
import com.jorkyin.barley.base.OnClickItemViewListener;
import com.jorkyin.barley.util.P2PParam;

import java.util.ArrayList;

/**
 * Created by Administrator on 2018/3/12.
 */
public class CameraRecyclerAdapter extends RecyclerView.Adapter<CameraRecyclerAdapter.ViewHolder> {
    private ArrayList<P2PParam> mData = new ArrayList<>();
    private OnClickItemViewListener mOnClickItemViewListener;

    public CameraRecyclerAdapter(ArrayList<P2PParam> data) {
        mData = data;
    }

    public void updateData(ArrayList<P2PParam> data) {
        this.mData = data;
        notifyDataSetChanged();
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        // 实例化展示的view
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_camera, parent, false);
        // 实例化viewholder

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

        holder.item_camera_image.setImageResource(R.drawable.ic_launcher_background);
        holder.item_camera_state.setText(mData.get(position).getState());
        holder.item_camera_image.setOnClickListener(onClickListener);
        holder.item_camera_folder.setOnClickListener(onClickListener);
        holder.item_camera_set.setOnClickListener(onClickListener);
    }

    @Override
    public int getItemCount() {
        return mData == null ? 0 : mData.size();
    }

    class ViewHolder extends RecyclerView.ViewHolder {
        ImageView item_camera_image;
        TextView item_camera_state;
        ImageView item_camera_folder;
        ImageView item_camera_set;

        ViewHolder(View itemView) {
            super(itemView);
            item_camera_image = itemView.findViewById(R.id.item_camera_image);
            item_camera_state = itemView.findViewById(R.id.item_camera_state);
            item_camera_folder = itemView.findViewById(R.id.item_camera_folder);
            item_camera_set = itemView.findViewById(R.id.item_camera_set);
        }
    }

    public void setOnClickItemViewListener(OnClickItemViewListener onClickItemViewListener) {
        mOnClickItemViewListener = onClickItemViewListener;
    }

}