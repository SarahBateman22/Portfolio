package com.example.spaceshootergame;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

import java.util.Random;

public class Me {

    Context context;
    Bitmap me;
    int ox, oy;
    boolean isAlive = true;
    int myVelocity;
    Random random;

    public Me(Context context){
        this.context = context;
        me = BitmapFactory.decodeResource(context.getResources(), R.drawable.me);
        random = new Random();
        resetMe();
    }

    public Bitmap getMe(){
        return me;
    }

    int getMyWidth(){
        return me.getWidth();
    }

    int getMyHeight(){
        return me.getHeight();
    }

    private void resetMe() {
        ox = random.nextInt(SpaceShooter.screenWidth);
        oy = SpaceShooter.screenHeight - me.getHeight();
        myVelocity = 10 + random.nextInt(6);
    }

}
