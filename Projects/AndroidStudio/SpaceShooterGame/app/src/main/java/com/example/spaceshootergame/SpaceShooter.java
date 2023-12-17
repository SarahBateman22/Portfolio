package com.example.spaceshootergame;
import static java.security.AccessController.getContext;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import android.view.Display;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Random;
import android.os.Handler;
import android.view.MotionEvent;
import android.view.View;

import java.util.logging.LogRecord;

public class SpaceShooter extends View {

    Context context;
    Bitmap background, lives;
    Handler handler;
    long UPDATE_MILLIS = 30;
    static int screenWidth, screenHeight;
    int points = 0;
    int life = 3;
    Paint scorePaint;
    int TEXT_SIZE = 80;
    boolean paused = false;
    Me me;
    Enemy enemy;
    Random random;
    ArrayList<Missile> enemyShots, myShots;
    boolean enemyExplosion = false;
    Explosion explosion;
    ArrayList<Explosion> explosions;
    boolean enemyShotAction = false;
    final Runnable runnable = new Runnable() {
        @Override
        public void run() {
            invalidate();
        }
    };

    public SpaceShooter(Context context){
        super(context);
        this.context = context;
        random = new Random();
        enemyShots = new ArrayList<>();
        myShots = new ArrayList<>();
        explosions = new ArrayList<>();
        Display display = ((Activity) getContext()).getWindowManager().getDefaultDisplay();
        Point size = new Point();
        display.getSize(size);
        screenWidth = size.x;
        screenHeight = size.y;
        me = new Me(context);
        enemy = new Enemy(context);
        background = BitmapFactory.decodeResource(context.getResources(), R.drawable.background);
        lives = BitmapFactory.decodeResource(context.getResources(), R.drawable.life);
        handler = new Handler();
        scorePaint = new Paint();
        scorePaint.setColor(Color.RED);
        scorePaint.setTextSize(TEXT_SIZE);
        scorePaint.setTextAlign(Paint.Align.LEFT);
    }

    @Override
    protected void onDraw(Canvas canvas){
        canvas.drawBitmap(background, 0 ,0, null);
        canvas.drawText("Pt: " + points, 0, TEXT_SIZE, scorePaint);
        for(int i = life; i >= 1; i--){
            canvas.drawBitmap(lives, screenWidth - lives.getWidth() * i, 0, null);
        }
        if(life == 0){
            paused = true;
            handler = null;
//            Intent intent = new Intent(context, GameOver.class);
//            intent.putExtra("points", points);
//            context.startActivity(intent);
            ((Activity) context).finish();
        }

        enemy.ex += enemy.enemyVelocity;
        if(enemy.ex + enemy.getEnemyWidth() >= screenWidth){
            enemy.enemyVelocity *= -1;
        }
        if(enemy.ex + enemy.getEnemyWidth() <= 0){
            enemy.enemyVelocity *= -1;
        }
        if((enemyShotAction == false) && enemy.ex >= 200 + random.nextInt(400)){
            Missile enemyMissile = new Missile(context, enemy.ex + enemy.getEnemyWidth()/2, enemy.ey);
            enemyShots.add(enemyMissile);
            enemyShotAction = true;
        }

        if(!enemyExplosion){
            canvas.drawBitmap(enemy.getEnemy(), enemy.ex, enemy.ey, null);
        }
        if(me.isAlive){
            if(me.ox > screenWidth - me.getMyWidth()){
                me.ox = screenWidth - me.getMyWidth();
            }
            else if(me.ox < 0){
                me.ox = 0;
            }
            canvas.drawBitmap(me.getMe(), me.ox, me.oy, null);
        }
        for(int i = 0; i < enemyShots.size(); i++){
            enemyShots.get(i).my += 15;
            canvas.drawBitmap(enemyShots.get(i).getMissile(), enemyShots.get(i).mx, enemyShots.get(i).my, null);
            if((enemyShots.get(i).mx >= me.ox) && enemyShots.get(i).mx <= me.ox + me.getMyWidth() && (enemyShots.get(i).my >= me.oy) && (enemyShots.get(i).my <= screenHeight)){
                life--;
                enemyShots.remove(i);
                explosion = new Explosion(context, me.ox, me.oy);
                explosions.add(explosion);
            }
            else if(enemyShots.get(i).my >= screenHeight){
                enemyShots.remove(i);
            }

            if(enemyShots.size() == 0){
                enemyShotAction = false;
            }
        }

        for(int i = 0; i < myShots.size(); i++){
            myShots.get(i).my -= 15;
            canvas.drawBitmap(myShots.get(i).getMissile(), myShots.get(i).mx, myShots.get(i).my, null);
            if((myShots.get(i).mx >= enemy.ex) && myShots.get(i).mx <= enemy.ex + enemy.getEnemyWidth() && myShots.get(i).my <= enemy.getEnemyHeight() && myShots.get(i).my >= enemy.ey){
                points++;
                myShots.remove(i);
                explosion = new Explosion(context, enemy.ex, enemy.ey);
                explosions.add(explosion);
            }
            else if (myShots.get(i).my <= 0){
                myShots.remove(i);
            }
        }

        for(int i = 0; i < explosions.size(); i++){
            canvas.drawBitmap(explosions.get(i).getExplosion(explosions.get(i).explosionFrame), explosions.get(i).ex, explosions.get(i).ey, null);
            explosions.get(i).explosionFrame++;
            if(explosions.get(i).explosionFrame > 7){
                explosions.remove(i);
            }
        }

        if(!paused){
            handler.postDelayed(runnable, UPDATE_MILLIS);
        }
    }

    @Override
    public boolean onTouchEvent(MotionEvent event){
        int touchX = (int) event.getX();
        if(event.getAction() == MotionEvent.ACTION_UP){
            if(myShots.size() < 3){
                Missile myMissile = new Missile(context, me.ox + me.getMyWidth()/2, me.oy);
                myShots.add(myMissile);
            }
        }
        if(event.getAction() == MotionEvent.ACTION_DOWN){
            me.ox = touchX;
        }
        if(event.getAction() == MotionEvent.ACTION_MOVE){
            me.ox = touchX;
        }
        return true;
    }
}
