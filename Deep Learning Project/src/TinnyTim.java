import java.util.Random;

public class TinnyTim 
{
	Random r = new Random();
	private int x, y, temp_x, temp_y;
	
	// Initializes the Q Martix with default values		
	Q_Learning qlearn;
	
	public TinnyTim(Basement Base)
	{
		qlearn = new Q_Learning();
		x = 4; // Initial X of Tim
		y = 4; // Initial Y of Tim
		
		temp_x = 4;
		temp_y = 4;
		
		
		Base.basement[x][y] = 'T';	
	}

	
	public void move_up()
	{		
		temp_x += -1;
		temp_y += 0;
	}
	
	public void move_down()
	{
		temp_x += 1;
		temp_y += 0;
	}
	
	public void move_left()
	{
		temp_x += 0;
		temp_y += -1;
	}
	
	public void move_right()
	{
		temp_x += 0;
		temp_y += 1;
	}
	

	// Checks the validity of the move, and also calculates reward for hitting/not hitting the wall
	public int check_Move(Basement Base)
	{
		int reward = 0;
		if(Base.basement[temp_x][temp_y] == 'X')
		{
			reward = -1;
			temp_x = x;
			temp_y = y;
		}
		else
		{
			if(Base.basement[x][y] != 'D')
			{
				Base.basement[x][y] = '\0';
			}
			
			// Move is legal so actually move tim now!
			x = temp_x;
			y = temp_y;			
		}
		return reward;
	}
	
	// Checks tile falls using the current location of Tim
	public int check_traps(Basement Base) {

		if((x == 1 && y == 3) || (x == 2 && y == 7) || (x == 3 && y == 4) || (x == 5 && y == 2) || (x == 6 && y == 5) || (x == 6 && y == 7) || (x == 7 && y == 2)) 
		{
			
			int Tile_Prob = r.nextInt(100);
			
			// Tim got slammed with the tile
			if(Tile_Prob < 50) 
			{
				return 10;
			}
		}
		return 0;	
	}
	
	public void update(Basement Base, int Reward, int State, int New_State, int Action) 
	{
		double Max_Action = qlearn.get_Max_Action_Value(qlearn.Q[New_State]);
					
		qlearn.Q[State][Action] += qlearn.Alpha * (Reward + qlearn.Discount_Factor * Max_Action - qlearn.Q[State][Action]);
	}
	
	
	// Moves Tim temporarily and validates the move, if it's legal then update the location of Tim
	public void move(Basement Base)
	{
		int Reward = 0;
		int State = x * 10 + y;
		
		int Action = qlearn.get_Max_Action(qlearn.Q[State]);
		
		
		// Code to deal with his 82% case
		int chance = r.nextInt(100);
		
		int finAction = -1;
		
		if(chance < 82)
		{
			finAction = Action;
		}
		else
		{
			// Tim now takes a random walk
			int random_walk;
			do
			{
				random_walk = r.nextInt(4);
				if(random_walk != Action)
					finAction = random_walk;
			}
			while(random_walk == Action);
		}
		
		switch(finAction)
		{
			case 0:
				move_up();
				
				Reward += check_Move(Base);
								
				break;
			
			case 1:
				move_down();
				
				Reward += check_Move(Base);
				
				break;
				
			case 2:
				move_left();
				
				Reward += check_Move(Base);
				
				break;
				
			case 3:
				move_right();
				
				Reward += check_Move(Base);
				
				break;
			
			default:
				break;
							
		}
		
		// Checks if he ate a donut
		if (Base.basement[x][y] == 'D')
		{
			Base.Donut_on_Map = false;
			Reward += 10;
		}
		
		Base.basement[x][y] = 'T'; // Placing Tim after the Move!
		
		Reward -= check_traps(Base); // Checking if he stepped into traps
		
		int New_State = 10 * x + y;
		
		update(Base, Reward, State, New_State, finAction);			
	}
	
	// Prints the policy from Q_Learning Class
	public void print_Policy(Basement Base)
	{
		Base.print_Policy(qlearn);
	}
	
	
	
	
}
