package com.example.spaceshootergame;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.MediaMetadataRetriever;

public class Explosion {

    Bitmap explosion[] = new Bitmap[9];
    int explosionFrame;
    int ex, ey;

    public Explosion(Context context, int ex, int ey){
        explosion[0] = BitmapFactory.decodeResource(context.getResources(), R.drawable.explosion0);
        explosion[1] = BitmapFactory.decodeResource(context.getResources(), R.drawable.explosion1);
        explosion[2] = BitmapFactory.decodeResource(context.getResources(), R.drawable.explosion2);
        explosion[3] = BitmapFactory.decodeResource(context.getResources(), R.drawable.explosion3);
        explosion[4] = BitmapFactory.decodeResource(context.getResources(), R.drawable.explosion4);
        explosion[5] = BitmapFactory.decodeResource(context.getResources(), R.drawable.explosion5);
        explosion[6] = BitmapFactory.decodeResource(context.getResources(), R.drawable.explosion6);
        explosion[7] = BitmapFactory.decodeResource(context.getResources(), R.drawable.explosion7);
        explosionFrame = 0;
        this.ex = ex;
        this.ey = ey;
    }

    public Bitmap getExplosion(int explosionFrame){
        return explosion[explosionFrame];
    }


}
