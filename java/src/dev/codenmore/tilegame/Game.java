package dev.codenmore.tilegame;

import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import dev.codenmore.tilegame.display.Display;


public class Game implements Runnable {
	private Shape [] shapes = new Shape[2];
	private Display display;
	public int width, height;
	public String title;
	
	private boolean running = false;
	private Thread thread;
	
	private BufferStrategy bs;
	private Graphics g;
	
	public Game(String title, int width, int height){
		this.width = width;
		this.height = height;
		this.title = title;
	}
	
	private void init(){
		display = new Display(title, width, height);


		
		// sides, radius, x,y, x_velocity, y_velocity, stiffness k
		shapes[0] = new Polygon(50,20,200,200,0.01,0,2500000);
		
		// 2nd shape is a line defined by 2 points
		Point [] MyPoints = new Point[2];
		for (int i = 0; i <2; i++){			
			MyPoints[i] = new Point(100 ,10 +60*i,0.01,0);		
		}
		shapes[1]= new Shape(MyPoints);

	}
	
	private void tick(){
		int num_steps = 200;
		double dt = 0.0005;
		for (int i = 0; i< num_steps; i++){
			for (int j =0; j<shapes.length;j++){
				shapes[j].tick(dt);
			}
			
		}
	}
	
	private void render(){
		bs = display.getCanvas().getBufferStrategy();
		if(bs == null){
			display.getCanvas().createBufferStrategy(3);
			return;
		}
		g = bs.getDrawGraphics();
		//Clear Screen
		g.clearRect(0, 0, width, height);
		//Draw Here!
		for (int j =0; j<shapes.length;j++){
			shapes[j].render(g);
		}
		
		
		
		//End Drawing!
		bs.show();
		g.dispose();
	}
	
	public void run(){
		
		init();
		
		int fps = 60;
		double timePerTick = 1000000000 / fps;
		double delta = 0;
		long now;
		long lastTime = System.nanoTime();
		long timer = 0;
		int ticks = 0;
		
		while(running){
			now = System.nanoTime();
			delta += (now - lastTime) / timePerTick;
			timer += now - lastTime;
			lastTime = now;
			
			if(delta >= 1){
				tick();
				render();
				ticks++;
				delta--;
			}
			
			if(timer >= 1000000000){
				System.out.println("Ticks and Frames: " + ticks);
				ticks = 0;
				timer = 0;
			}
		}
		
		stop();
		
	}
		
	
	
	public synchronized void start(){
		if(running)
			return;
		running = true;
		thread = new Thread(this);
		thread.start();
	}
	
	public synchronized void stop(){
		if(!running)
			return;
		running = false;
		try {
			thread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	
}




