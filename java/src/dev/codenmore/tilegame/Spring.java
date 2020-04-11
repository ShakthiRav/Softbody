package dev.codenmore.tilegame;

public class Spring {
	private Point point_i, point_j;
	// spring constant k and and damping constant lambda
	private double nat_len, k, lambda, prev_len;
	
	public Spring(Point point_i, Point point_j, double k, double lambda){
		this.point_i = point_i; this.point_j =point_j;
		double dx = point_i.x - point_j.x;
		double dy= point_i.y - point_j.y;
		nat_len =  Math.sqrt(dx*dx +dy*dy);
		prev_len = nat_len;
		this.k = k; this.lambda = lambda;
					
	}
	
	public void applyForce(){
		double dx = point_i.x - point_j.x;
		double dy= point_i.y - point_j.y;
		double d = Math.sqrt(dx*dx +dy*dy);
		double e = (d - nat_len)/nat_len;
		
		// haven't bothered with dampening yet really 
		point_i.addSpringForce(-dx/d*e * k, -dy/d*e* k);
		point_j.addSpringForce(dx/d*e * k, dy/d*e* k);
		
		prev_len = d;
	}
	

}
