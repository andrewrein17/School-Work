/*
*
* Simple game of blackjack
* @author Andrew Rein 
*
* Date Modified : 7/14/2019
*/
import java.lang.Math;
import java.util.stream.*;
import java.util.Scanner;
import java.lang.*;
import java.util.Arrays; 
import java.util.ArrayList;
public class Blackjack {
	
	private static ArrayList<Integer> playerHand = new ArrayList<Integer>();
	private static ArrayList<Integer> dealerHand = new ArrayList<Integer>();
	private static int currentChips = 1000;
	private static int currentBet = 0;
	
	
	public static int getFirstCard() { //Returns a random first player card between 1-10.		
		int firstCard = (int)Math.ceil(Math.random()* 10);
		
		return firstCard;
	  }
	public static int getSecondCard() { //Returns a random second player card between 1-10.
		int secondCard = (int)Math.ceil(Math.random()* 10);
		
		return secondCard;
	  }
		
	public static int firstDealerCards() { //Returns a random first dealer card between 1-10.
		int firstDealerCard = (int)Math.ceil(Math.random()* 10);
		return firstDealerCard;
	  }
	
	public static int secondDealerCards() { //Returns a random second dealer card between 1-10.
		int secondDealerCard = (int)Math.ceil(Math.random()* 10);
		
		return secondDealerCard;
	  }
	
	public static int hit() { //Returns a new random card between 1-10.
		
		int newCard = (int)Math.ceil(Math.random()* 10);
		isHighAce();
		return newCard;
	}
	
	public static void chipBet() {
		System.out.println("How much would you like to bet?");
		Scanner betScan = new Scanner( System.in );
	    currentBet = betScan.nextInt();
	}
	
	public static void playBlackjack() { //Gives players the choice to play blackjack.
		String play = "Yes";
		String noPlay = "No";
		
	    System.out.println("Play Blackjack?");
	    
	    Scanner playScan = new Scanner( System.in );
	    String playChoice = playScan.nextLine();
	    
	    playChoice = playChoice.replaceAll("\\s", "");
	    boolean doPlay = playChoice.equalsIgnoreCase(play);
	    boolean dontPlay = playChoice.equalsIgnoreCase(noPlay);
	    
	    if (dontPlay == true) {
	    	System.exit(0);
	    }
	    
	    playerHand.clear();
	    dealerHand.clear();
	    System.out.println("You have " + currentChips + " chips!");
	    System.out.println();
	    chipBet();
	    System.out.println();
        dealHand();
		
		System.out.println("Your total is " + playerHandSum() + ".");
		System.out.println();
		System.out.println("The dealer has a " + dealerHand.get(0) + ".");
		System.out.println();

		hitOrStand();
		
		if (playerHandSum() > 21) {
			System.out.println();
			System.out.println("Player bust! You lose!");
			
			currentChips -= currentBet;
			
			System.out.println();
			playBlackjack();
		}
	
		System.out.println("The dealer reveals a " + dealerHand.get(1) + ".");
		System.out.println("The dealer's total is " + dealerHandSum() + ".");
		System.out.println();
		
        dealerDraw();
       
        System.out.println();
        
        if (dealerHandSum() > 21) {
        	System.out.println("Dealer bust! You win!");
        	currentChips += currentBet;
        	System.out.println();
        	playBlackjack();
        }
 		
        if (isWin() == true) {
        	System.out.println();
        	System.out.println("You have " + playerHandSum() + " and the dealer has " + dealerHandSum() + " You win!");
        	
        	currentChips += currentBet;
        	
        	System.out.println();
        	playBlackjack();
        }
        else if (playerHandSum() == dealerHandSum()) {
        	System.out.println();
        	System.out.println("You have " + playerHandSum() + " and the dealer has " + dealerHandSum() + " Push!");
        	playBlackjack();
        }
        else {
        	System.out.println();
        	System.out.println("You have " + playerHandSum() + " and the dealer has " + dealerHandSum() + " You lose!");
        	
        	currentChips -= currentBet;
        	
        	System.out.println();
        	playBlackjack();
        } 
        
        playBlackjack();

       }	
	
	public static void isHighAce() { //Allows players to pick a high or low ace.
		String highAce = "high";
		String lowAce = "low";
		
		for(int i = 0; i < playerHand.size(); i++) {
			if (playerHand.get(i) == 1) {
				
			System.out.println("Would you like a high or low ace?");
			Scanner firstAce = new Scanner( System.in );
		    String firstAceResult = firstAce.nextLine();
			    
			firstAceResult = firstAceResult.replaceAll("\\s", "");
			boolean highEqual = firstAceResult.equalsIgnoreCase(highAce);
			boolean lowEqual = firstAceResult.equalsIgnoreCase(lowAce);
		    
			if (highEqual == true) {
				playerHand.set(i, 11);
			  }
			}
		}
	}
	
	public static void dealHand() { //Fills two arraylists with "cards"
		playerHand.add(getFirstCard());
		playerHand.add(getSecondCard());
		System.out.println("You have a " + playerHand.get(0) + " and a " + playerHand.get(1) + ".");
		isHighAce();
		if (isBlackjack() == true) {
			System.out.println("Player blackjack! You win!");
			playBlackjack();
		}
		dealerHand.add(firstDealerCards());
		dealerHand.add(secondDealerCards());
	}
	
	public static int playerHandSum() {
		int sum = 0;
		for(int i = 0; i < playerHand.size(); i++) {
			sum += playerHand.get(i);
		}
		return sum;	
	}
	
	public static int dealerHandSum() {
		int sum = 0;
		for(int i = 0; i < dealerHand.size(); i++) {
			sum += dealerHand.get(i);
		}
		return sum;	
	}
	
	public static void hitOrStand() { //Allows the player to hit or stand.
		String hitChoice = "hit";
		String standChoice = "stand";
		
		System.out.println("Would you like to hit or stand?");
		Scanner hitOrStand = new Scanner( System.in );
	    String result = hitOrStand.nextLine();
	    
	    result = result.replaceAll("\\s", "");
	    boolean hitEqual = result.equalsIgnoreCase(hitChoice);
	    boolean standEqual = result.equalsIgnoreCase(standChoice);
	    
	    if (hitEqual == true) {
	    	playerHand.add(hit());
	    	isHighAce();
	    	System.out.println("You got a " + playerHand.get(playerHand.size()-1) +  ".");
	    	System.out.println("Your new total is " + playerHandSum() + ".");
	    	
	    	if (playerHandSum() > 21) {
				return;
			}
	    	hitOrStand();
	    }
	}
	
	public static boolean isWin() { //Tests for a win
		if (playerHandSum() > dealerHandSum()) {
			return true;
		}
		else
		return false;
	}
	
	public static boolean isBlackjack() { //Tests for a player blackjack.
		if ((playerHand.get(0) == 1 && playerHand.get(1) == 10) || (playerHand.get(0) == 10 && playerHand.get(1) == 1) ) {
			return true;
		}
		else return false;
	}
	
	public static void dealerDraw() { //Makes the dealer draw to at least 17
		if (dealerHandSum() < 17) {
			dealerHand.add(hit());
			System.out.println("The dealer drew a " + dealerHand.get(dealerHand.size()-1) +  ".");
			System.out.println("The dealer's new total is " + dealerHandSum() + ".");
			dealerDraw();
		}
		else return;
	}
	
	public static void main(String [] args) {
		playBlackjack();				
    } 
}
  	
