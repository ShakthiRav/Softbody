package dev.codenmore.tilegame;

import java.awt.Graphics;

public class Polygon extends Shape{

	public Polygon(int sides, double r , double x, double y , double vx, double vy, double k)
	{
		this.k =k;
		points = new Point[sides*2];
		springs = new Spring[sides*3];
		for (int i = 0; i < sides; i++){
			points[2*i] = new Point(x + r*Math.cos(2*Math.PI/ sides *i),y + r*Math.sin(2*Math.PI/ sides *i),vx,vy);
			points[2*i+1] = new Point(x + r/2*Math.cos(2*Math.PI/ sides *i),y + r/2*Math.sin(2*Math.PI/ sides *i),vx,vy);

			
		}
		
		for (int i = 0; i < sides; i++){

			springs[3*i] = new Spring(points[2*i], points[2*i+1],k,1);
			springs[3*i+1] = new Spring(points[2*i], points[(2*i+2)%(2*sides)],k,1);
			springs[3*i+2] = new Spring(points[2*i+1], points[(2*i+3)%(2*sides)],k,1);
			
		}
				
	}
	
	public void render(Graphics g){
		int l= points.length;
		for (int i = 0; i < l; i+=2){
			
			
			g.drawLine((int)(points[i].x), (int)(points[i].y), (int)(points[(i+2)%l].x), (int)(points[(i+2)%l].y));
			
		}
		g.drawLine((int)(points[0].x), (int)(points[0].y), (int)(points[1].x), (int)(points[1].y));
		
				
	}
}
