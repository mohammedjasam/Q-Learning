public class Setw
{	
	// ==== setwL ======================================================================
	//
	// - Set field width left -
	//
	// This method mimics the C++ 'setw' function, which is used to format data to the
	// screen. This function right justifies string data of size "width," filling 
	// the width to the left of the string with whitespace (' ').
	//
	// - USAGE -
	// setwL(<String> the text you wish to format, <int> size of width to be formated);
	//
	// =================================================================================	
	public void setwL(String str, int width)
	{		
		for (int x = str.length(); x < width; ++x) 
		{
			System.out.print(' ');	
		}
		System.out.print(str);
	}// end of setwL
	
	// ==== setwR ======================================================================
	//
	// - Set field width right -
	//
	// This method mimics the C++ 'setw' function, which is used to format data to the
	// screen. This function left justifies string data of size "width," filling 
	// the width to the right of the string with whitespace (' ').
	//
	// - USAGE -
	// setwR(<String> the text you wish to format, <int> size of width to be formated);
	//
	// =================================================================================
	public void setwR(String str, int width)
	{
		System.out.print(str);
		for (int x = str.length(); x < width; ++x) 
		{
			System.out.print(' ');	
		}
	}// end of setwR
	
	// ==== setwLF ======================================================================
	//
	// - Set field width left fill -
	//
	// This method mimics the C++ 'setw' & 'setfill' functions, which are used to format 
	// data to the screen. This function right justifies string data of size "width," 
	// filling the width to the left of the string with a filler character.
	//
	// Use this method (instead of using 'setwL/setwR') when you want so specify the  
	// type of filler you want to use
	//
	// - USAGE -
	// setwLF(<String> the text you wish to format, 
	// <int> size of width to be formated, <char> the type of filler to be displayed);
	//
	// =================================================================================		
	public void setwLF(String str, int width, char fill)
	{		
		for (int x = str.length(); x < width; ++x) 
		{
			System.out.print(fill);	
		}
		System.out.print(str);
	}// end of setwLF
	
	// ==== setwRF ======================================================================
	//
	// - Set field width right fill -
	//
	// This method mimics the C++ 'setw' & 'setfill' functions, which are used to format 
	// data to the screen. This function left justifies string data of size "width," 
	// filling the width to the right of the string with a filler character.
	//
	// Use this method (instead of using 'setwL/setwR') when you want so specify the  
	// type of filler you want to use
	//
	// - USAGE -
	// setwLF(<String> the text you wish to format, 
	// <int> size of width to be formated, <char> the type of filler to be displayed);
	//
	// =================================================================================
	public void setwRF(String str, int width, char fill)
	{
		System.out.print(str);
		for (int x = str.length(); x < width; ++x) 
		{
			System.out.print(fill);	
		}
	}// end of setwRF
}// http://programmingnotes.org/