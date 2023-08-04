import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class Solution {
    public static void main(String args[] ) throws Exception {
        class Acquaintance {
        public String name;
        public Acquaintance(String name)
        {
            this.name = name;
        }
        public void getStatus() {
            System.out.println(name+" is just an acquaintance\n.");
        };
    } 
        
        class Friend extends Acquaintance {
        public String homeTown;
        public Friend(String name, String homeTown)
        {
            this.homeTown = homeTown;
            super.name = name;
        }
        @Override
        public void getStatus()
        {
            System.out.println(super.name+" is a friend and he is from " + homeTown + " \n.");
        }
    } 
        class BestFriend extends Friend {
        public String favoriteSong;
        public BestFriend(String name, String homeTown, String favoriteSong)
        {
            this.favoriteSong = favoriteSong;
            super.homeTown = homeTown;
            super.name = name;
        }
        @Override
        public void getStatus()
        {
            System.out.println(super.name+" is my best friend. He is from "+super.homeTown+" and his favorite song is "+favoriteSong);
        }
    }
        Scanner sc = new Scanner(System.in);
        String sub = sc.nextLine();
        int t = Integer.parseInt(sub);
        for (int i = 0; i < t; i++) {
            
            String[] input = sc.nextLine().split(" ");

            if(input[0].equals("Acquaintance")) {
                String friendName = input[1];
                Acquaintance acq = new Acquaintance(friendName);
                acq.getStatus();
            } else if (input[0].equals("Friend")) {
                String friendName = input[1];
                String homeTown = input[2];
                Friend frnd = new Friend(friendName, homeTown);
                frnd.getStatus();
            } else if(input[0].equals("BestFriend")) {
                String friendName = input[1];
                String homeTown = input[2];
                String favoriteSong = input[3];
                BestFriend bf = new BestFriend(friendName, homeTown, favoriteSong);
                bf.getStatus();
            }
        }
    }
}

// public class Solution {
//     public static void main(String args[] ) throws Exception {
//         /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//         Scanner sc = new Scanner(System.in);
//         String sub = sc.nextLine();
//         int t = Integer.parseInt(sub);
//         for (int i = 0; i < t; i++) {
            
//             String[] input = sc.nextLine().split(" ");

//             if(input[0].equals("Acquaintance")) {
//                 String friendName = input[1];
//                 Acquaintance acq = new Acquaintance(friendName);
//                 acq.getStatus();
//             } else if (input[0].equals("Friend")) {
//                 String friendName = input[1];
//                 String homeTown = input[2];
//                 Friend frnd = new Friend(friendName, homeTown);
//                 frnd.getStatus();
//             } else if(input[0].equals("BestFriend")) {
//                 String friendName = input[1];
//                 String homeTown = input[2];
//                 String favoriteSong = input[3];
//                 BestFriend bf = new BestFriend(friendName, homeTown, favoriteSong);
//                 bf.getStatus();
//             }
//         }
//     }
// }