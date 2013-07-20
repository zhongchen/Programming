
import java.util.*;

public class Test {

	static void test(String nums, String out, int start) {
        if (nums == null || start == nums.length()) {
            System.out.println(out);
            return;
        }
        int i = nums.charAt(start) - '0';
        if (i != 0) {
            test(nums, out + (char) (i + 64), start + 1);
            if (start + 1 < nums.length()) {
                i = Integer.parseInt(nums.substring(start, start + 2));
                if (i <= 26) {
                    test(nums, out + (char) (i + 64), start + 2);
                }
            }
        }

    }
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//test("6513", "", 0);
		System.out.println("Start");
		// TODO Auto-generated method stub
		//intString it = new intString();
		//it.test();
		
		IntervalInsertion it = new IntervalInsertion();
		it.test();
		it.test2();
	}

}

class intString {
	public intString(){}
	
	public void test(){
		String temp = "abcdefghijklmnopqrstuvwxyz";
		ArrayList<Integer> array = new ArrayList<Integer>();
		array.add(3);
		array.add(0);
		//array.add(1);
		//array.add(3);
		String result ="";
		convert(array, result, temp.toCharArray());
		System.out.println("End");
	}
	
		
	private void convert(List<Integer> arr, String result, char[] table){
		if(arr.size()==0){
			System.out.println(result);
			return;
		}
		
		if(arr.size()==1){
			int t = arr.get(0);
			if(t!=0){
				System.out.println(result+table[t-1]);
			}
			return;
		}
		
		int t = arr.get(0);
		if(t!=0){
			convert(arr.subList(1, arr.size()), result+table[t-1], table);
			//System.out.println(result.toString());
			int temp = 10*t + arr.get(1);
			if(temp <=26){
				convert(arr.subList(2, arr.size()), result+table[temp-1], table);
			}
			
		}
		
	}
	
	
	
}