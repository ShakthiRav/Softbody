package dev.codenmore.tilegame;

public class Point {
	public double x, y, prev_x, prev_y ;
	private double mass =1;
	private double f_x;
	private double mu = 0.3;
	private double g = 9.8;
	private double f_y =g;
	
	
	public Point(double x,double y, double vx, double vy){
		
		this.x =x;
		this.y = y;
		this.prev_x = x - vx;
		this.prev_y = y-vx;
	}
	
	public void tick(double dt){
		// verlet integration
		double temp_x = x; double temp_y= y;
		
		x = 2*x - prev_x + dt*dt * f_x/mass; 
		y = 2*y - prev_y + dt*dt * f_y/mass;
		
		prev_x = temp_x; prev_y = temp_y;
		

		if (y >= 360-5){

			x+= (prev_x-x)/ Math.abs(prev_x-x) * mu * Math.abs((  f_y ))/mass *dt*dt ;

			y = 360-5; prev_y = 360-5;						
		}
		if (y<=0){
			y = 0; prev_y = 0;
			
		}
		
		if (x >= 640){
			y+= (prev_y-y)/ Math.abs(prev_y-y) * mu * Math.abs((  f_x ))/mass *dt*dt ;
			x=640;prev_x =640;
		}
		
		if (x <= 0){
			y+= (prev_y-y)/ Math.abs(prev_y-y) * mu * Math.abs((  f_x ))/mass *dt*dt ;
			x=0;prev_x =0;
		}
	}
	
	public void addSpringForce(double F_x, double F_y){
		f_x +=F_x; f_y +=F_y;				
	}
	
	public void resetForce(){
		f_x = 0; f_y = g * mass;		
	}
	
	

}
