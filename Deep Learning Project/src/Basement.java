import java.util.Random;

public class Basement 
{
	int Base_Height = 10;
	int Base_Width = 10;
	
	char basement[][] = new char[Base_Height][Base_Width];
	
	boolean Donut_on_Map = false;
	
	public Basement()
	{
		// Outside walls 
		
		for (int i = 0; i < basement[0].length; i++) 
		{
			basement[0][i] = 'X';
		}
		
		for (int i = 0; i < basement[0].length; i++) 
		{
			basement[9][i] = 'X';			
		}
		
		for (int i = 0; i < basement[0].length; i++) 
		{
			basement[i][0] = 'X';			
		}
		
		for (int i = 0; i < basement[0].length; i++) 
		{
			basement[i][9] = 'X';			
		}
		
		
		
		// Inner Walls
		
		basement[6][4] = 'X';
		basement[7][4] = 'X';
		basement[8][4] = 'X';
		basement[4][6] = 'X';
		basement[5][6] = 'X';
		basement[6][6] = 'X';
		basement[2][4] = 'X';
		basement[2][5] = 'X';
		basement[2][6] = 'X';
		basement[2][2] = 'X';
		basement[3][2] = 'X';
		basement[4][2] = 'X';
		
	}
	
	public void drop_donut()
	{
		if (!Donut_on_Map)
		{
			Random r = new Random();
			int Donut_probability = r.nextInt(100);
			
			// Dropping Donut in one of 4 corners
			
			if(Donut_probability < 25) 
			{				
				int corner = r.nextInt(4); // generates prob to select the corner
				
				switch (corner) 
				{
					case 0:
						basement[1][1] = 'D';  // Top left
						break;
						
					case 1:
						basement[1][8] = 'D';  // Top right
						break;
						
					case 2:
						basement[8][1] = 'D';  // Bottom left
						break;
						
					case 3:
						basement[8][8] = 'D';  // Bottom right
						break;
			
					default:
						break;
				}
				
				Donut_on_Map = true; // Donut has been dropped in the basement!
			}
		}		
	}
	
	public void render()  // Deprecated function, initially was used to show the movement of Tim in the base
	{		
		for (int i = 0; i < 10; i++) 
		{
			for (int j = 0; j < 10; j++) 
			{				
				if(basement[i][j] == '\0')
				{
					System.out.print(" ");
				}
				
				System.out.print(basement[i][j] + "   ");				
			}			
			System.out.println();
		}
	}
	
	// This function is used to print the policy, it takes the qlearning obj and extracts the policy Q Matrix
	public void print_Policy(Q_Learning qlearn) 
	{
		for(int i=0; i<10; i++) 
		{
			for(int j =0; j< 10; j++) 
			{
				// Excluding walls
				if( i == 0 || j == 0 || i == 9 || j == 9)
				{
					System.out.print("X" + "   ");
				}
				else if( (i == 6 && j == 4) || (i == 7 && j == 4) || (i == 8 && j == 4) || (i == 4 && j == 6) || (i == 5 && j == 6) || (i == 6 && j == 6) || (i == 2 && j == 4) || (i == 2 && j == 5) || (i == 2 && j == 6) || (i == 2 && j == 2) || (i == 3 && j == 2) || (i == 4 && j == 2) )
				{
					System.out.print("X" + "   ");
				}
				else 
				{
					// Prints the policy
					switch (qlearn.get_Max_Action(qlearn.Q[10 * i + j])) // Extracts the max value for that cell in q maritx
					{
						case 0:
							System.out.print("^" + "   ");  // Top is highest
							break;
							
						case 1:
							System.out.print("v" + "   ");  // Bottom is highest
							break;
							
						case 2:
							System.out.print("<" + "   ");  // Left is highest
							break;
							
						case 3:
							System.out.print(">" + "   ");  // Right is highest
							break;
					}
				}				
			}
			System.out.println("\n");
		}
	}
	
}
