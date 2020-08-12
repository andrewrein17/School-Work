/*
*
* An updated version of the blackjack game
* @author Andrew Rein 
*
* Date Modified : 8/12/2020
*/
using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Globalization;
using System.Runtime.CompilerServices;
using System.Threading;

namespace Test
{
    class BlackJack
    {

        private static List<Card> deck = new List<Card>();
        private static List<Card> playerHand = new List<Card>();
        private static List<Card> dealerHand = new List<Card>();

        private struct Card
        {
            public String suit;
            public int number;
        }

        //Fills the deck of the players
        public static void FillDeck()
        {
            String cardSuit = "";

            for (int i = 0; i < 4; i++)
            {
                switch (i)
                {
                    case 0:
                        cardSuit = "diamond";
                        break;
                    case 1:
                        cardSuit = "club";
                        break;
                    case 2:
                        cardSuit = "heart";
                        break;
                    case 3:
                        cardSuit = "spade";
                        break;
                }

                for (int k = 1; k < 14; k++)
                {
                    Card card;
                    card.number = k;
                    card.suit = cardSuit;
                    deck.Add(card);
                }

            }

        }

        //Function that controls the dealing of cards
        private static void Deal(Boolean isPlayer)
        {

            Random rand = new Random();
            int card = rand.Next(0, deck.Count);

            if (isPlayer)
            {
                playerHand.Add(deck[card]);
                deck.RemoveAt(card);
            }
            else
            {
                dealerHand.Add(deck[card]);
                deck.RemoveAt(card);
            }

        }

        //Prints the cards that appear in the console
        private static void DrawCard(Card card)
        {
            Console.WriteLine("+--+");
            Console.Write("|");

            switch (card.number)
            {
                case 1:
                    Console.Write("A");
                    break;
                case 11:
                    Console.Write("J");
                    break;
                case 12:
                    Console.Write("Q");
                    break;
                case 13:
                    Console.Write("K");
                    break;
                default:
                    Console.Write(card.number);
                    break;
            }

            if (card.suit == "diamond") Console.WriteLine("d|");
            else if (card.suit == "club") Console.WriteLine("c|");
            else if (card.suit == "spade") Console.WriteLine("s|");
            else Console.WriteLine("h|");

            Console.WriteLine("+--+");

        }

        //An empty card 
        private static void DrawEmpty()
        {
            Console.WriteLine("+--+");
            Console.WriteLine("|  |");
            Console.WriteLine("+--+");
        }

        //Shows the hands of the players once the bets have been made
        private static void ShowHands(Boolean gameOver)
        {
            Console.WriteLine("Dealers hand");
            if (gameOver)
            {
                foreach (Card card in dealerHand)
                {
                    DrawCard(card);
                }
            }
            else
            {
                DrawCard(dealerHand[0]);
                DrawEmpty();
            }
            Console.WriteLine();

            Console.WriteLine("Your hand");

            foreach (Card card in playerHand)
            {
                DrawCard(card);
            }
        }

        //Keeps track of the total of both the players
        private static int Total(Boolean isPlayer)
        {
            int count = 0;

            if (isPlayer)
            {
                foreach (Card card in playerHand)
                {
                    count += card.number;
                }
            }
            else
            {
                foreach (Card card in dealerHand)
                {
                    count += card.number;
                }
            }

            return count;
        }

        static void Main(string[] args)
        {

            Boolean gameRunning = true;
            Boolean gameOver = false;

            while (gameRunning)
            {

                FillDeck();

                Deal(false);
                Deal(false);
                Deal(true);
                Deal(true);

                ShowHands(false);

                if (Total(true) > 21)
                {
                    Console.WriteLine("Bust! You lose.");
                    gameOver = true;
                    goto PlayAgain;
                }
                else if (Total(false) > 21)
                {
                    Console.WriteLine("Dealer bust! You win.");
                    gameOver = true;
                    goto PlayAgain;
                }

                Console.WriteLine("Hit or stand? (Your total is " + Total(true) + ")");
                String choice = Console.ReadLine();

                while (String.Compare(choice, "hit", StringComparison.OrdinalIgnoreCase) == 0 && gameOver == false)
                {
                    Deal(true);
                    ShowHands(false);

                    if (Total(true) > 21)
                    {
                        Console.WriteLine("Bust! You lose.");
                        gameOver = true;

                        goto PlayAgain;
                    }

                    Console.WriteLine("Hit or stand? (Your total is " + Total(true) + ")");
                    choice = Console.ReadLine();
                }

                gameOver = true;
                ShowHands(true);

                while (Total(false) <= 17)
                {
                    Deal(false);
                    Console.WriteLine("The dealer drew a " + dealerHand[dealerHand.Count - 1].number + ".");
                    Thread.Sleep(1200);
                    ShowHands(true);
                    Thread.Sleep(1200);

                    if (Total(false) > 21)
                    {
                        Console.WriteLine("Dealer bust! You win.");
                        goto PlayAgain;
                    }
                }

                if (Total(true) > Total(false) && gameOver && Total(true) <= 21) 
                {
                    Console.WriteLine("The dealer has " + Total(false) + " and you have " + Total(true) + ". You win!");
                }
                else Console.WriteLine("The dealer has " + Total(false) + " and you have " + Total(true) + ". You lose!");

                PlayAgain:

                playerHand.Clear();
                dealerHand.Clear();
                deck.Clear();
                Console.WriteLine();
                Console.WriteLine("Play again?");
                String playAgain = Console.ReadLine();

                if (String.Compare(playAgain, "no", StringComparison.OrdinalIgnoreCase) == 0) gameRunning = false;
                
            }
        }
    }
}
