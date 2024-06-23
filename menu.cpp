#include "menu.h"

Menu::Menu(){
	exit = 0;
}

void Menu::display_menu(){

	Music music;
	music.openFromFile("img/music.flac");   //load music
   	music.play();

	int score_arr[100]={0};   //array that stores high scores
	
	Game g;
	Font font;
    	font.loadFromFile("img/TIMESR.ttf");   //load font
    
	menu_texture.loadFromFile("img/IMG_20230512_172225.jpg");
	menu_background.setTexture(menu_texture);
	menu_background.setScale(1.5, 2.15);
	
	RenderWindow MBG(VideoMode(780, 780), "OOP-Project, Spring-2023");

	
//display menu screen here
	
	while (MBG.isOpen()){
		MBG.clear(Color::Black); //clears the screen
		MBG.draw(menu_background);    // setting background


// add functionality of all the menu options here

		if (Keyboard::isKeyPressed(Keyboard::E)){   //exit
			MBG.close();
			exit = 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::P)){   //play game
			MBG.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::I)){   //instructions
			menu_texture.loadFromFile("img/IMG_20230514_032013.jpg");
			menu_background.setTexture(menu_texture);
			menu_background.setScale(1.5, 2.15);
		}
		if (Keyboard::isKeyPressed(Keyboard::H)){
			MBG.close();
			
			RenderWindow HSBG(VideoMode(780, 780), "OOP-Project, Spring-2023");
			
			Texture hs_texture;
			Sprite hs_background;
			
			hs_texture.loadFromFile("img/high.jpeg");
			hs_background.setTexture(hs_texture);
			hs_background.setScale(1.5, 2.15);
			
			
			int x=0;
	    		string xyz=" ";
	    		
	    		ifstream file("highscore.txt");
	    		ifstream file2("HIGHSCORE.txt");
	    		
	    		while (getline(file,xyz))
	    		{
	    			score_arr[x] = stoi(xyz);
	    			x += 1;
	    		}
	    		file.close();
    			sort(score_arr, 100);
			
			
			while (HSBG.isOpen()){
				HSBG.clear(Color::Black); //clears the screen
				HSBG.draw(hs_background);    // setting background
			
				Text high_score(std::string("HIGH SCORE"), font, 60);
				high_score.setFillColor(sf::Color::Yellow);
				high_score.setPosition(1.f,1.f);
				high_score.move(180.f,500.f);
				HSBG.draw(high_score);
				
				Text play(std::string("Press 'P' to Play"), font, 40);
				play.setFillColor(sf::Color::Yellow);
				play.setPosition(1.f,1.f);
				play.move(240.f,350.f);
				HSBG.draw(play);
				
				Text score1(std::string("1) " + std::to_string(score_arr[0])), font, 40);
				score1.setFillColor(sf::Color::Yellow);
				score1.setPosition(1.f,1.f);
				score1.move(240.f,100.f);
				HSBG.draw(score1);
				
				Text score2(std::string("2) " + std::to_string(score_arr[1])), font, 40);
				score2.setFillColor(sf::Color::Yellow);
				score2.setPosition(1.f,1.f);
				score2.move(240.f,170.f);
				HSBG.draw(score2);
				
				Text score3(std::string("3) " + std::to_string(score_arr[2])), font, 40);
				score3.setFillColor(sf::Color::Yellow);
				score3.setPosition(1.f,1.f);
				score3.move(240.f,240.f);
				HSBG.draw(score3);
				
				
				
				if (Keyboard::isKeyPressed(Keyboard::P)){   //play game
					HSBG.close();
				}
				
				Event e;
		
				while (MBG.pollEvent(e)){  
				    if (e.type == Event::Closed){ // If cross/close is clicked/pressed
				    	exit = 1;
					HSBG.close(); //close the game                        	    
				}
				}
				HSBG.display();
			}
		}
		
		
		Event e;
		
		while (MBG.pollEvent(e)){  
		    if (e.type == Event::Closed){ // If cross/close is clicked/pressed
		    	exit = 1;
		        MBG.close(); //close the game                        	    
		}
		}
		MBG.display();
	}
	




//if Start game option is chosen 
    	if (exit == 0)
		g.start_game();



}

void Menu::sort(int arr[], int size)
{
	int temp=0;
	for (int i=0; i<size-1; ++i)
		for (int j=0; j<size-i-1; ++j)
			if (arr[j]<arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
}
