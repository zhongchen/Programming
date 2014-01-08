import java.util.*;
/*
 * Given a set of non-overlapping Intervals, insert a new Interval into the Intervals (merge if necessary).

You may assume that the Intervals were initially sorted according to their start times.

Example 1:
Given Intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new Interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * 
 * 
 */
class Interval{
	int start, end;
	Interval(){start=0; end=0;}
	Interval(int s, int e){
		start = s;
		end = e;
	}
}

class IntervalInsertion {
	ArrayList<Interval> merge(ArrayList<Interval> list, Interval v){
		ArrayList<Interval> newList = new ArrayList<Interval>();
		int start = v.start;
		int end = v.end;
		
		for(Interval i: list){
			if(i.end>=start&&i.start<=end){
				if(i.end > end)
					end = i.end;
				if(i.start < start)
					start = i.start;
			}else{
				
				newList.add(i);
			}
		}
		newList.add(new Interval(start, end));
		return newList;
	}
	
	void print(ArrayList<Interval> list){
		for(Interval i: list){
			System.out.println("[" + i.start + "," + i.end + "]");
		}
	}
	void test(){
		ArrayList<Interval> list = new ArrayList<Interval>();
		list.add(new Interval(1,3));
		list.add(new Interval(6,9));	
		Interval v = new Interval(2,5);
		ArrayList<Interval> newList = merge(list, v);
		print(newList);
		
	}
	
	void test2(){
		ArrayList<Interval> list = new ArrayList<Interval>();
		list.add(new Interval(1,2));
		list.add(new Interval(3,5));
		list.add(new Interval(6,7));
		list.add(new Interval(8,10));
		list.add(new Interval(12,16));
		Interval v = new Interval(4,9);
		ArrayList<Interval> newList = merge(list,v);
		print(newList);
	}
}


