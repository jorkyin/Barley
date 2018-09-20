package com.jorkyin.barley.activity.RecyclerAdapter;

import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.jorkyin.barley.R;
import com.jorkyin.barley.base.OnClickItemViewListener;
import com.jorkyin.barley.util.P2PParam;

import java.util.ArrayList;

/**
 * Created by Administrator on 2018/3/12.
 */
//处理搜索到UID显示
public class SearchRecyclerAdpter extends RecyclerView.Adapter<SearchRecyclerAdpter.ViewHolder> {
    private OnClickItemViewListener mOnItemClickListener;
    private ArrayList<P2PParam> mData ;
    public void updateData(ArrayList<P2PParam> data) {
        mData=data;
        notifyDataSetChanged();
    }

    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_search, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, final int position) {

        holder.item_search_uid.setText(mData.get(position).getUID());
        holder.item_search_ip.setText(mData.get(position).getIP());
        holder.item_search_state.setText(mData.get(position).getState());

        View.OnClickListener onClickListener = new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mOnItemClickListener.onRecyclerViewItemClick(view, position);
            }
        };
        holder.itemView.setOnClickListener(onClickListener);
    }

    @Override
    public int getItemCount() {
        return mData == null ? 0 : mData.size();
    }

    class ViewHolder extends RecyclerView.ViewHolder {
        TextView item_search_uid;
        TextView item_search_ip;
        TextView item_search_state;

        ViewHolder(View itemView) {
            super(itemView);
            item_search_uid = itemView.findViewById(R.id.item_search_uid);
            item_search_ip = itemView.findViewById(R.id.item_search_ip);
            item_search_state = itemView.findViewById(R.id.item_search_state);
        }
    }

    public void setOnItemClickListener(OnClickItemViewListener onClickItemViewListener) {
        this.mOnItemClickListener = onClickItemViewListener;
    }
}