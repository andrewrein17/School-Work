import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Random;
import java.util.Collections;
import java.util.Scanner;
import java.lang.Math;

public class GoFish {

	private static ArrayList<Integer> playerHand = new ArrayList<Integer>();
	private static ArrayList<Integer> npcHand = new ArrayList<Integer>();
	private static ArrayList<Integer> Deck = new ArrayList<Integer>();
	private static ArrayList<Integer> Test = new ArrayList<Integer>();
	private static ArrayList<Integer> TestB = new ArrayList<Integer>();
	
	public static int playerBooks = 0;
	public static int npcBooks = 0;
	
	public static void main(String [] args) throws InterruptedException {
		
		/*Test.add(5);
		Test.add(3);
		Test.add(6);
		Test.add(5);
		Test.add(7);
		Test.add(5);
		Test.add(6);
		Test.add(1);
		System.out.println(Test);
		isBook(Test);
		System.out.println(Test);
		
		TestB.add(5);
		TestB.add(5);
		TestB.add(0);
		TestB.add(5);*/
		
		playGoFish();

	}
	
	public static void playGoFish() throws InterruptedException { //Starts the game of go fish 
		FillDeck();
		FillHand(playerHand);
		FillHand(npcHand);
		while (Deck.size() != 0) {
		System.out.println();
		
		
		playerTurn();
		Thread.sleep(1000);
		npcTurn();
			
		
		}
	}
	public static void FillDeck() { //Fills the deck at the start of the game 
		
		for(int i=0;i<4;i++) { //Fills the deck with one of each card suit
			for(int k = 1; k<14;k++) {
			  Deck.add(k);
			  
			}
		}
	 }
	
	public static void FillHand(ArrayList<Integer> array){ //Fills a hand with card from the deck then removes those cards from the deck
		
		Random r = new Random();		
		for (int i=0;i<7;i++) { 
		    int Card = Deck.get(r.nextInt(Deck.size()));
		    int index = Deck.indexOf(Card);
		    Deck.remove(index); //Removes care at that index
			array.add(Card); //Adds card to deck
			Collections.sort(array);
		}
	}
	
	public static boolean isBook(ArrayList<Integer> array) { //Checks to see if either player has a book
		
	    int count = 0;
		Collections.sort(array);
		//System.out.println(array);
		for(int i=0; i<array.size()-1;i++){
			
			
			if(array.get(i) == array.get(i+1)) { //Checks to see if the next card equals the current
				count++;
				if (count == 3) { //Removes the 4 cards from the hand 
					array.remove(i+1); 
					array.remove(i); 
					array.remove(i-1); 
					array.remove(i-2); 
					return true;
				}
			}
			if(array.get(i) != array.get(i+1)) { //Resets count if the two cards are not equal
				count = 0;
			}
			
		}
				 
		  return false;
	 }
	
	public static int draw(ArrayList<Integer> array) { //Draws and removes a single random card from the deck
		
		Random r = new Random();
		int Card = Deck.get(r.nextInt(Deck.size()));
		int index = Deck.indexOf(Card);
        Deck.remove(index); //Removes card from the deck
	    array.add(Card); //add card to hand array 
	    Collections.sort(array);
	    return Card;
		
	}
	
	public static void playerTurn() throws InterruptedException { //Everything needed for the player's turn
		
		System.out.println("You have " + playerBooks + " books!");
		System.out.println("Here is your hand.");
		
		System.out.println(playerHand);
		System.out.println();
		Thread.sleep(1500);
		if (isBook(playerHand) == true) {
			System.out.println("You completed a book!");
			playerBooks++;
		}
		System.out.println("What card would you like? (1-13)");
		
		 Scanner cardScan = new Scanner( System.in );
		 int cardChoice = cardScan.nextInt();
		 
		 int cardCount = cardSearch(cardChoice, playerHand, npcHand); //Checks to see if the card the player selected was in the other player's hand
		 
		 System.out.println("The computer had " + cardCount + " " + cardChoice + "s.");
		 
		
		 Thread.sleep(1500);
		 if (cardCount == 0) {
			 System.out.println("Your opponent says \"Go fish!\"");
			 Thread.sleep(1500);
			 System.out.println("You take a card from the pile.");
			 Thread.sleep(1500);
			 System.out.println("You got a " + draw(playerHand) + ".");
			 System.out.println();
			 if (isBook(playerHand) == true) {
					System.out.println("You completed a book!");
					playerBooks++;
					Thread.sleep(1500);
					System.out.println();
				}
			 Thread.sleep(1500);

		 }
		 
		 if (cardCount > 0 ) {
			 System.out.println();
			 if (isBook(playerHand) == true) {
					System.out.println("You completed a book!");
					playerBooks++;
					Thread.sleep(1500);
					System.out.println();
				}
			 playerTurn();
		 }
		
	}
	
	public static int cardSearch(int a, ArrayList<Integer> arrayP, ArrayList<Integer> arrayC) { //Searches a players hand for a card
		int count = 0;
		int key = a; 
		
		for (int i=0; i<arrayC.size(); i++) {
			
			if (arrayC.get(i) == key){
				count++;
				int card = arrayC.get(i);
				arrayC.remove(i);			
				arrayP.add(card);
			    i--;

			}
		}
		Collections.sort(arrayC);
	    Collections.sort(arrayP);
		return count;
	}
	
	public static void npcTurn() throws InterruptedException {
		
		System.out.println("It's the computer's turn!");
		if (isBook(npcHand) == true) {
			System.out.println("The computer completed a book!");
			npcBooks++;
			Thread.sleep(2000);
			System.out.println();
		}
		Thread.sleep(2000);
		System.out.println("The computer has " + npcBooks + " books!");
		
		Thread.sleep(2000);
		
		Random r = new Random();
		//int npcCard = Deck.get(r.nextInt(npcHand.size()));
		
		int npcCard = (int)Math.ceil(Math.random() * 13);
		
		System.out.println("The computer says \"Give me your " + npcCard + "s.\"");
		Thread.sleep(2000);
		int npcCount = cardSearch(npcCard, npcHand, playerHand);
		System.out.println("You had " + npcCount + " " + npcCard + "s!");
		Thread.sleep(2000);
		 if (npcCount == 0) {
			 System.out.println("You say \"Go fish!\"");
			 Thread.sleep(2000);
			 System.out.println("The computer takes a card from the pile.");
			 Thread.sleep(2000);
			 if (isBook(npcHand) == true) {
					System.out.println("The computer completed a book!");
					npcBooks++;
					Thread.sleep(2000);
					System.out.println();
			 }
                 
		 }
		 System.out.println(npcHand);
		 if (npcCount > 0 ) {
			 System.out.println();
			 if (isBook(npcHand) == true) {
					System.out.println("The computer completed a book!");
					npcBooks++;
					Thread.sleep(2000);
					System.out.println();
			 }
			 npcTurn();
		 }
	}
	
	
  }

	
	
	
	
