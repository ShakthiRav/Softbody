package dev.codenmore.tilegame;
import java.util.ArrayList;
import java.util.Map;
import java.awt.Graphics;


public class Shape {
	public double k = 2500000/2;

	public Point[] points;
	public Spring[] springs;
	
	public Shape(){
		
	}
	
	public Shape(Point [] points){
		int num_points = points.length;
		this.points = points;
		this.springs = new Spring[(num_points)*(num_points -1)/2];
		
		int s_i =0;
		for(int i = 0 ; i < num_points; i++){
			for (int j = i+1 ; j < num_points; j++){
				System.out.println(num_points * i +j-i-1);
				springs[s_i] = new Spring(points[i], points[j], k, 1);
				s_i+=1;
			}			
		}	
	}
	
	public void render(Graphics g){
		int l= points.length;
		for (int i = l/2; i < l; i++){
			
			
			g.drawLine((int)(points[i].x), (int)(points[i].y), (int)(points[(i+1)%(l/2)+l/2].x), (int)(points[(i+1)%(l/2)+l/2].y));
			
		}
		g.drawLine((int)(points[0].x), (int)(points[0].y), (int)(points[(25)%l].x), (int)(points[(25)%l].y));
				
	}

	public void tick(double dt) {
		// TODO Auto-generated method stub
		
		
		for (int i = 0; i< points.length;i++){
			points[i].resetForce();
		}
		
		for (int i = 0; i < springs.length; i++){
			springs[i].applyForce();			
		}
		
		for (int i = 0; i< points.length;i++){
			points[i].tick(dt);
			
		}
	}
	
	
	
	
	
	
	

}
