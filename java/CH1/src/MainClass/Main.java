package MainClass;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static class MovieTicket {
		String movieName;
		String roomType;
		int price;
		
		public MovieTicket(String movie, String room , int price) {
			movieName = movie;
			roomType = room;
			this.price = price;
		}
	}
	
	void bubbleSort(ArrayList<MovieTicket> mTick) {
		for (int i = 0;i < mTick.size() - 1;i++) {
			for (int j = 0;j < i - 1;j++) {
				if (mTick.get(j).movieName.compareToIgnoreCase(mTick.get(j+1).movieName) < 0) {
					MovieTicket temp = mTick.get(j);
					mTick.set(j, mTick.get(j+1));
					mTick.set(j + 1, temp);
				}
			}
		}
	}
	
	static MovieTicket addTicketMenu() {
		Scanner scan = new Scanner(System.in);
		MovieTicket movie = new MovieTicket("", "", 2);
		while (true) {
			System.out.print("Input the movie name: ");
			String temp = scan.next();
			if (temp.length() >= 3 && temp.length() <= 15) {
				movie.movieName = temp;
				break;
			}
		}
		while (true) {
			System.out.print("Input the room type: ");
			String temp = scan.next();
			System.out.println(temp);
			if (temp == "Regular" || temp == "Premier") {
				movie.roomType = temp;
				break;
			}
		}
		while (true) {
			System.out.print("Input Price: ");
			int temp = scan.nextInt();
			if (temp > 0) {
				movie.price = temp;
				break;
			}
		}
		return movie;
	}

	public static void main(String[] args) {
		ArrayList<MovieTicket> movieTickets = null;
		Scanner scan = new Scanner(System.in);
		while (true) {
			System.out.println("$$\\    $$\\   $$\\     $$$$$$\\           \n$$ |   $$ |  $$ |    \\_$$  _|          \n$$ |   $$ |$$$$$$\\     $$ |  $$\\   $$\\ \n\\$$\\  $$  |\\_$$  _|    $$ |  \\$$\\ $$  |\n \\$$\\$$  /   $$ |      $$ |   \\$$$$  / \n  \\$$$  /    $$ |$$\\   $$ |   $$  $$<  \n   \\$  /     \\$$$$  |$$$$$$\\ $$  /\\$$\\ \n    \\_/       \\____/ \\______|\\__/  \\__|\n");
			System.out.println("1. Add Ticket\n2. View List Order\n3. Manage Order\n4. Sorting\n0. Exit");
			System.out.print(">> ");
			int choice = scan.nextInt();
			switch (choice) {
				case 1: {
					MovieTicket temp = addTicketMenu();
					if (temp != null) {
						movieTickets.add(temp);
						System.out.println(temp.movieName);
					}
				}
			}
		}
	}

}
