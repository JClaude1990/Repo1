package jeanc;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class libraymenu {
	static ArrayList<String>books=new ArrayList<>();
	static final String FILE_NAME="books.txt";

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		loadBooksFromFile();
		
		int choice;
		do {
			System.out.println("/n=============Libray Menu==========");
			System.out.println("1.Add book");
			System.out.println("2.Issue book");
			System.out.println("3.Return book");
			System.out.println("4.Display available books");
			System.out.println("5.Exit");
			System.out.println("Enter your choice");
			choice=sc.nextInt();
			sc.nextLine();
			
			switch(choice) {
			case 1:
				System.out.println("Enter book name or add");
				String addBook=sc.nextLine();
				books.add(addBook);
				System.out.println("Book added successfully.");
				
				break;
			case 2:
			System.out.println("Enter the book name to issue");
			String issueBook=sc.nextLine();
			if(books.remove(issueBook)) {
				System.out.println("Book issued successfully.");
				
			}else {
				System.out.println("Book not available.");
			}
			break;
			case 3:
				System.out.println("Enter book name to return:");
				String returnBook=sc.nextLine();
				System.out.println("Book reurned successfull.");
				break;
			case 4:
				if(books.isEmpty()) {
					System.out.println("No books available.");
					
				}else {
					System.out.println("Available books:");
					for(int i=0;i<books.size();i++) {
						System.out.println((i+1)+"."+books.get(i));
					}
						
					}
				break;
			case 5:
				saveBooksToFile();
				System.out.println("Date saved.Exiting program:");
				break;
				default:
					System.out.println("Invalid choice");
				}
				
				
		}
			while(choice!=5);
			sc.close();
				
			}
			private static void saveBooksToFile() {
	
		
	}
			static void loadBooksFromFile() {
				try {
					File file=new File(FILE_NAME);
					
					if(!file.exists()) {
						return;
					}
					Scanner scanner =new Scanner(file);
					while(scanner.hasNextLine()) {
					
						books.add(scanner.nextLine());
					}
					scanner.close();
				}catch (IOException e) {
						
							System.out.println("Error loading books.");
						}
					}
			static void saveBooksToFile() {
				
						try {
							FileWriter writer=new FileWriter(FILE_NAME);
							
							for(String book:books);{
								writer.write(book +"\n");
							}
							writer.close();
								
						
					}catch(IOException e){
						System.out.println("Error saving books");
					}
				}
			
				
				
			
			
		

	}


