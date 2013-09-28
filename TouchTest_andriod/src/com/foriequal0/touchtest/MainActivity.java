package com.foriequal0.touchtest;

import android.os.Bundle;
import android.app.Activity;
import android.graphics.Color;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.View;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

	@Override
	public boolean onTouchEvent(MotionEvent event) {
		View root = findViewById(R.id.mainview);

		// Set the color
		switch(event.getAction()){
		case MotionEvent.ACTION_DOWN:
			root.setBackgroundColor(Color.WHITE);
			break;
		case MotionEvent.ACTION_CANCEL:
		case MotionEvent.ACTION_UP:
		case MotionEvent.ACTION_OUTSIDE:
			root.setBackgroundColor(Color.BLACK);
			break;
		}
		return super.onTouchEvent(event);
	}

}
