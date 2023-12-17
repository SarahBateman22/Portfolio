package com.example.spaceshootergame;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

public class Missile {

    Bitmap missile;
    Context context;
    int mx, my;

    public Missile(Context context, int mx, int my){
        this.context = context;
        missile = BitmapFactory.decodeResource(context.getResources(), R.drawable.missile);
        this.mx = mx;
        this.my = my;
    }

    public Bitmap getMissile(){
        return missile;
    }
}
