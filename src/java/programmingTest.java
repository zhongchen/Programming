import java.util.*;

//In this file, I 
public class programmingTest {
	
	static int abs(int a){
		return (a<0)? -a : a;
	}
	
	static int sumWithoutAdding(int a, int b){
		if(b==0) return a;
		
		int sum = a^b;
		int carry = (a&b)<<1;
		
		return sumWithoutAdding(sum, carry);		
	}

	static void sumTest(){
		int a1=1, b1=1;
		int a2=-1, b2=-1;
		int a3=1, b3=-1;
		int a4=0, b4=0;
		System.out.println(sumWithoutAdding(a1,b1));
		System.out.println(sumWithoutAdding(a2,b2));
		System.out.println(sumWithoutAdding(a3,b3));
		System.out.println(sumWithoutAdding(a4,b4));
		System.out.println(abs(a2));
		System.out.println(abs(a1));
		System.out.println(a4^b4);
		System.out.println(a1^b1);
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		sumTest();
	}

}
