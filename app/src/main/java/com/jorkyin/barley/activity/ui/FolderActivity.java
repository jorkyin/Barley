package com.jorkyin.barley.activity.ui;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.GridLayoutManager;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.OrientationHelper;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.widget.ImageView;
import android.widget.TextView;

import com.jorkyin.barley.R;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FolderActivity extends AppCompatActivity {
    private ArrayList<FolderInfo> mCameraFolderList = new ArrayList<>();
    private FolderRecyclerAdpter mCameraFolderAdpter;
    private RecyclerView mCameraFolerRecyclerView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // 隐藏当前Activity的标题
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_camera_folder);

        mCameraFolerRecyclerView = findViewById(R.id.folder_recycler_view);

        setData();
        showView();
    }

    private void showView() {
        RecyclerView.LayoutManager cameraRecyclerLayoutLayoutManager = new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false);
        FolderRecyclerAdpter cameraFolderAdpter = new FolderRecyclerAdpter(this, mCameraFolderList);

        mCameraFolerRecyclerView.setLayoutManager(cameraRecyclerLayoutLayoutManager);
        mCameraFolerRecyclerView.setAdapter(cameraFolderAdpter);

    }

    private void setData() {
        for (int index = 0; index < 3; index++) {
            List<Map<String, Object>> photoList;
            //图标
            int icno[] = {R.mipmap.album_title_icon,
                    R.mipmap.album_title_icon,
                    R.mipmap.album_title_icon,
                    R.mipmap.album_title_icon,
                    R.mipmap.album_title_icon,
                    R.mipmap.album_title_icon};

            //图标下的文字
            String name[] = {"时钟", "信号", "宝箱", "秒钟", "大象", "FF"};
            photoList = new ArrayList<Map<String, Object>>();
            for (int i = 0; i < icno.length; i++) {
                Map<String, Object> map = new HashMap<String, Object>();
                map.put("img", icno[i]);
                map.put("text", name[i]);
                map.put("src", icno[i]);
                photoList.add(map);
            }

            //添加数据
            mCameraFolderList.add(new FolderInfo("rtsp://admin:8888@192.168.1.101", photoList));

        }
    }

    class FolderInfo {
        private String mUID;
        private List<Map<String, Object>> mPhotoList;

        FolderInfo(String uid, List<Map<String, Object>> photoList) {
            mUID = uid;
            mPhotoList = photoList;
        }

        public String getmUID() {
            return mUID;
        }

        public void setmUID(String mUID) {
            this.mUID = mUID;
        }

        List<Map<String, Object>> getmPhotoList() {
            return mPhotoList;
        }

        public void setmPhotoList(List<Map<String, Object>> mPhotoList) {
            this.mPhotoList = mPhotoList;
        }
    }

    class FolderRecyclerAdpter extends RecyclerView.Adapter<FolderRecyclerAdpter.ViewHolder> {
        private ArrayList<FolderInfo> mData = new ArrayList<>();
        private Context mContext;

        FolderRecyclerAdpter(Context context, ArrayList<FolderInfo> data) {
            mContext = context;
            mData = data;
        }

        public void updateData(ArrayList<FolderInfo> data) {
            this.mData = data;
            notifyDataSetChanged();
        }

        @Override
        public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            // 实例化展示的view
            View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_folder, parent, false);
            // 实例化viewholder

            return new ViewHolder(view);
        }

        @Override
        public void onBindViewHolder(ViewHolder holder, int position) {
            holder.item_folder_calendar.setText("01/02");
            holder.item_folder_year.setText("2018");
            holder.item_folder_time.setText("09:00-10:00");

            GridLayoutManager layoutManager = new GridLayoutManager(mContext, 4, OrientationHelper.VERTICAL, false);
            PhotoRecyclerAdpter photoRecyclerAdpter = new PhotoRecyclerAdpter(mData.get(position).getmPhotoList());
            holder.item_folder_photo.setLayoutManager(layoutManager);
            holder.item_folder_photo.setAdapter(photoRecyclerAdpter);
        }

        @Override
        public int getItemCount() {
            return mData == null ? 0 : mData.size();
        }

        class ViewHolder extends RecyclerView.ViewHolder {
            TextView item_folder_year;
            TextView item_folder_calendar;
            TextView item_folder_time;
            RecyclerView item_folder_photo;

            ViewHolder(View itemView) {
                super(itemView);
                item_folder_year = itemView.findViewById(R.id.item_folder_year);
                item_folder_calendar = itemView.findViewById(R.id.item_folder_calendar);
                item_folder_time = itemView.findViewById(R.id.item_folder_time);
                item_folder_photo = itemView.findViewById(R.id.item_folder_photo);
            }
        }
    }


    class PhotoRecyclerAdpter extends RecyclerView.Adapter<PhotoRecyclerAdpter.ViewHolder> {
        private List<Map<String, Object>> mData;
        private LayoutInflater inflater;

        PhotoRecyclerAdpter(List<Map<String, Object>> data) {
            this.mData = data;
        }

        public void updateData(List<Map<String, Object>> data) {
            this.mData = data;
            notifyDataSetChanged();
        }

        @Override
        public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_photo, parent, false);
            return new ViewHolder(view);
        }

        @Override
        public void onBindViewHolder(PhotoRecyclerAdpter.ViewHolder holder, int position) {
            holder.item_photo_img.setImageResource(R.drawable.ic_launcher_background);
        }

        @Override
        public int getItemCount() {
            return mData == null ? 0 : mData.size();
        }

        class ViewHolder extends RecyclerView.ViewHolder {
            ImageView item_photo_img;

            ViewHolder(View itemView) {
                super(itemView);
                item_photo_img = itemView.findViewById(R.id.item_photo_img);

            }
        }
    }
}
