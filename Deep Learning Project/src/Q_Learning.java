import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Random;

import javax.swing.text.NumberFormatter;

public class Q_Learning 
{
	Setw format = new Setw(); // Used for formatting
	double Alpha = 0.4; // Learning rate
	double Discount_Factor = 0.1; // used to diminish the value of previous records after a 
	int States = 100;
	int Actions = 4;
	
	double Q[][] = new double[States][Actions]; // Creates a q matrix
	
	public Q_Learning()
	{
		for(int i = 0; i < 100; i++)
		{
			for(int j = 0; j < 4; j++) 
			{
				Q[i][j] = 100; // assigns the default value as 100
			}
		}
	}
	
	
	public void print_Q_Matrix() 
	{				
		for(int i = 0; i < States; i++) 
		{
			for(int j = 0; j< Actions; j++) 
			{
				format.setwR(String.valueOf(Q[i][j]), 30); // prints the value of Q with formatiing
			}			
			System.out.println();
		}
	}
	
	// Prints the final expected reward of each cell
	public void print_Expected_Reward() 
	{				
		NumberFormat f = new DecimalFormat("#.##########");
		for(int i = 1; i <= States; i++) 
		{
			double x = get_Max_Action_Value(Q[i-1]);
			if (x == 100.0)
			{
				format.setwR(String.valueOf("-----------------------"), 25);
			}
			else
			{
			
				format.setwR(String.valueOf((get_Max_Action_Value(Q[i-1]))), 25);
			}
//			format.setwR(String.valueOf(f.format(get_Max_Action_Value(Q[i-1]))), 10);
			if(i % 10 == 0)
			System.out.println();
		}
	}
	
	// Returns the action with max q value
	public int get_Max_Action(double base_action[]) 
	{
		double Max_Value = -Double.MAX_VALUE;
		int Target_Index = -1;
		
		for(int i = 0; i < base_action.length; i++) 
		{
			if(base_action[i] > Max_Value) 
			{
				Max_Value = base_action[i];
				Target_Index = i;
			}
		}
		return Target_Index;
	}
	
	// Returns the max q value of the cell
	public double get_Max_Action_Value(double base_action[]) 
	{
		double Max_Value = -Double.MAX_VALUE;
		
		for(int i = 0; i < base_action.length; i++) 
		{
			if(base_action[i] > Max_Value) 
			{
				Max_Value = base_action[i];
			}
		}
		return Max_Value;
	}
	
	
	
}
