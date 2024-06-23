#include "game.h"
#include<fstream>

Game::Game(){
	p=new Spaceship("img/player_ship.png");
	a=nullptr;
	m=nullptr;
	d=nullptr;
	//add=nullptr;
	level=1;
	score=0;
	direction=0;
	bg_texture.loadFromFile("img/background.jpg");
	background.setTexture(bg_texture);
	background.setScale(2, 1.5);
}

void Game::start_game(){

	int done=0;
	srand(time(0));
	RenderWindow window(VideoMode(780, 780), title);

	Clock clock;
	float timer=0;
	float bomb_timer=0.0;
	float enemy_timer=0.0;
	float monster_timer=0.0;
	float dragon_timer=0.0;
	float fire_timer=0.0;
	float add_timer=0.0;
	bool drawn=0;
	bool monster_drawn=0;
	bool dragon_drawn=0;
	bool add_drawn=0;
	bool bomb_drawn=0;

	Font font;
	font.loadFromFile("img/TIMESR.ttf");   //load font

	Bullet bullet[20];


	int cnt=0;
	int add_choice=0;


	for (int i=0;i<20;++i){
	bullet[i].tex.loadFromFile("img/PNG/Lasers/laserBlue03.png");
	bullet[i].sprite.setTexture(bullet[i].tex);

	}

	while (window.isOpen())
	{

		for (int i=0;i<20;++i){
			bullet[i].tex.loadFromFile("img/PNG/Lasers/laserBlue03.png");
			bullet[i].sprite.setTexture(bullet[i].tex);
		}
		float time = clock.getElapsedTime().asSeconds(); 
		clock.restart();
		timer += time;
		monster_timer += time;
		dragon_timer += time;
		add_timer += time;
		float enemy_time = timer;
	 	Event e;

		if (add_timer > 5 && add_drawn == 0){
		add_drawn = 1;
		add_choice = 1 + rand()%3;
		if (add_choice == 1)
		    p->add = new Danger;
		else if (add_choice == 2)
		    p->add = new Lives;
		else if (add_choice == 3)
		    p->add = new Fire;
		}
		if (done < 3){
	 		enemy_timer += time;
	 		bomb_timer += time;
			if (drawn == 0 && enemy_timer>5){
				int choice = 1 + rand()%3;
				if (choice == 1)
			    		a = new Alpha;
			    	else if (choice == 2)
			    		a = new Beta;
			    	else if (choice == 3)
			    		a = new Gamma;
			    	a->makeShapes(level);
			    	
			    	drawn = 1;
			    	done++;
		    	}
		}
		if (done == 3){
			enemy_timer += time;
		}

		if (monster_timer >= 38){
			if (!monster_drawn){
				m = new Monster;
				monster_drawn=1;
			}
		}

		if (dragon_timer > 47.0f && dragon_drawn == 0){
			if (!dragon_drawn){
				d = new Dragon;
				dragon_drawn = 1;
			}
    		}

	
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }


	if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up)){
		p->tex.loadFromFile("img/bilal2.png");
		p->sprite.setTexture(p->tex);
		p->sprite.setScale(1.5,1.5);
		direction = -1;
		if (!p->fir){
		    	for (int i=0;i<20;++i){
		    		bullet[i].tex.loadFromFile("img/left_scale.png");
				bullet[i].sprite.setTexture(bullet[i].tex);
		    		bullet[i].sprite.setScale(3,3);
		    	}
		}
		else{
		    	for (int i=0;i<20;++i){
			    	bullet[i].tex.loadFromFile("img/PNG/Effects/left.png");
				bullet[i].sprite.setTexture(bullet[i].tex);
				bullet[i].sprite.setScale(4,4);
			}
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Up)){
		p->tex.loadFromFile("img/bilal1.png");
		p->sprite.setTexture(p->tex);
		p->sprite.setScale(1.5,1.5);
		direction = 1;
			if (!p->fir){
			    	for (int i=0;i<20;++i){
			    		bullet[i].tex.loadFromFile("img/right_scale.png");
					bullet[i].sprite.setTexture(bullet[i].tex);
			    		bullet[i].sprite.setScale(3,3);
			    	}
			}
			else{
			    	for (int i=0;i<20;++i){
				    	bullet[i].tex.loadFromFile("img/PNG/Effects/right.png");
					bullet[i].sprite.setTexture(bullet[i].tex);
					bullet[i].sprite.setScale(4,4);
				}
			}
		}
	else{
		p->tex.loadFromFile("img/player_ship.png");
		p->sprite.setTexture(p->tex);
		p->sprite.setScale(0.75,0.75);
		direction = 0;
			if (!p->fir){
			    	for (int i=0;i<20;++i){
			    		bullet[i].tex.loadFromFile("img/PNG/Lasers/laserBlue03.png");
					bullet[i].sprite.setTexture(bullet[i].tex);
			    		bullet[i].sprite.setScale(1,1);
			    	}
			}
			else{
			    	for (int i=0;i<20;++i){
				    	bullet[i].tex.loadFromFile("img/PNG/Effects/fire17.png");
					bullet[i].sprite.setTexture(bullet[i].tex);
					bullet[i].sprite.setScale(2,2);
				}
			}
	}
    
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
        
        if (Keyboard::isKeyPressed(Keyboard::P)){   //If P is pressed
	    RenderWindow pause_window(VideoMode(780, 780), title);   //New window opens for pause
	    
	    Texture pw_texture;
	    Sprite pw_background;
	    
	    pw_texture.loadFromFile("img/background.jpg");
	    pw_background.setTexture(pw_texture);
	    pw_background.setScale(2, 1.5);
	    
            while(pause_window.isOpen()){
                pause_window.clear(Color::Black); //clears the screen
		pause_window.draw(pw_background);    // setting background
            	
            	Text Pause(std::string("PAUSE"), font, 70);
		Pause.setFillColor(sf::Color::Yellow);
		Pause.setPosition(1.f,1.f);
		Pause.move(280.f,100.f);
		pause_window.draw(Pause);
		
		Text Resume(std::string("Press 'R' to Resume"), font, 40);
		Resume.setFillColor(sf::Color::Yellow);
		Resume.setPosition(1.f,1.f);
		Resume.move(240.f,350.f);
		pause_window.draw(Resume);
		
		Text Exit(std::string("Press 'E' to Resume"), font, 40);
		Exit.setFillColor(sf::Color::Yellow);
		Exit.setPosition(1.f,1.f);
		Exit.move(240.f,450.f);
		pause_window.draw(Exit);
		
            	
            	if (Keyboard::isKeyPressed(Keyboard::R))   //If R is pressed
            	    pause_window.close();                  //Pause window close and game resume
            	
            	if (Keyboard::isKeyPressed(Keyboard::E))   //If E is pressed
            	    exit(0);                               //all windows closed
            	
            	pause_window.display();
            }
        }
            

	if (!p->fir){
		p->fire(&bullet[cnt]);
		cnt++;
		for (int i=0;i<cnt;++i)
			p->moveBullet(&bullet[i],direction);
        }
        else if (p->fir){
		fire_timer += time;
		p->fire(&bullet[cnt]);
		cnt++;
		for (int i=0;i<cnt;++i)
			p->moveBullet(&bullet[i],direction);
        }
        
        
	/////////////////////////////////////////////////
	/////    Call your functions here          /////
	///////////////////////////////////////////////

	window.clear(Color::Black); //clears the screen
	window.draw(background);    // setting background
	
	
	
	if (p->health > 0){
		window.draw(p->sprite); // setting player on screen
		window.draw(bullet[cnt].sprite);
	}

	
//CHECKS BASED ON TIME
	if (add_timer > 13){
		if (add_choice == 1){
			if (p->add->sprite.getPosition().y >= 700){
				if (p->add->killed == 1){
					score += 5;
				}
			}
		}
		add_timer = 0.0;
		add_drawn = 0;
	}
	if (fire_timer >= 5){
		p->fir = 0;
		fire_timer = 0;
	}
	if(enemy_timer>12){
		a->healthCheck(score,level);
		enemy_timer=0;
		drawn = 0;
		if (done<3)
		delete a;
	}
	if (monster_timer > 43){
		monster_timer = 0;
		monster_drawn = 0;
		if (m->killed == 0)
			score += 40;
		delete m;
	}
	
	if (dragon_timer > 52){
		dragon_timer = 0;
		monster_timer = 0;
		enemy_timer = 0;
		add_timer = 0;
		fire_timer = 0;
		timer = 0;
		drawn = 0;
		monster_drawn = 0;
		dragon_drawn = 0;
		add_drawn = 0;
		if (d->killed == 0)
			score += 50;
		level++;
		done = 0;
		delete d;
	}
	
	//cout<<bomb_timer<<"     "<<bomb_drawn<<endl;
//FUNCTIONS DEPENDANT ON CORRESPONDING BOOL VALUES
	if (drawn){
	
		for (int i=0;i<a->size;++i)
			window.draw(a->sprite[i]);
		a->move(level); 
		a->checkCollision(bullet,*p);
		
		
		if (bomb_timer > a->bomb_time){// && enemy_time>1){   //BOMB FALLS FOR 1 SEC
			bomb_timer = 0.0;
			bomb_drawn = 1;
		}
		
		if (bomb_timer > 1.5f && bomb_timer <= a->bomb_time){
			bomb_drawn = 0;
			a->bomb_x = a->get_minX() + rand()%240;
			a->b->sprite.setPosition(a->bomb_x,440);	
		}
		if (a->bomb_killed && bomb_timer > 1.495 && bomb_timer < 1.50){   //check if bomb and ship made contact
			p->health -= 1000;
			a->bomb_killed = 0;
		}
		if (bomb_drawn){
			a->fall_bomb(window);
		}
		
		a->checkShip(*p);
		
	}
	
	if (add_drawn){
		window.draw(p->add->sprite);
		p->add->fall();
		p->add->checkShip(p->sprite.getPosition().x, p->sprite.getPosition().y, p->health, p->lives, p->fir);
	}
	
	if (monster_drawn){
    		window.draw(m->sprite);
    		if (!(monster_timer>39 && monster_timer<41))
    			m->attack(window);
    		m->checkShip(*p);
    		m->move(level);
    }
	
	if (dragon_drawn){
		window.draw(d->sprite);
		d->attack(window,*p);
		d->checkShip(*p);
	}
	
	if (p->health <= 0){
		p->health = 2999;
		p->lives -= 1;
	}
	
	if (p->lives <= 0 || level > 3){   //GAME OVER
		window.close();
		
		bool entered=0;
		RenderWindow GO(VideoMode(780, 780), title);
		Texture gobg_texture;
		Sprite GOBG;
		
		gobg_texture.loadFromFile("img/game_over.jpeg");
		GOBG.setTexture(gobg_texture);
		GOBG.setScale(1.5, 2.15);
		int i=0;
		
		Event event;
		sf::String playerInput;
		sf::Text playerText("",font,40);
		playerText.setPosition(340,575);
//		playerText.setColor(sf::Color::Yellow);
		
		while (GO.isOpen()){
			GO.clear(Color::Black); //clears the screen
			GO.draw(GOBG);    // setting background
			
			while (GO.pollEvent(event)){
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128){
					    playerInput += event.text.unicode;
					    playerText.setString(playerInput);
					}
				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Escape){
					    exit(0);
					}
					if (event.key.code == Keyboard::Enter){
					    entered = 1;
					    break;
					}
				}
				
					
			}
			if (entered){
				break;
			}
			
			Text your_score(std::string("Your Score: " + std::to_string(score)), font, 40);
			your_score.setFillColor(sf::Color::Yellow);
			your_score.setPosition(1.f,1.f);
			your_score.move(20.f,400.f);
			GO.draw(your_score);
			
			GO.draw(playerText);
			GO.display();
		}
		
		ofstream file("highscore.txt", ios::app);   //append file
		file<<to_string(score)<<endl;   //add score
		file.close();   //close file
		
		ofstream file2("HIGHSCORE.txt", ios::app);   //append file
		file2<<(string)playerInput<<"|"<<to_string(score)<<endl;   //add score
		file2.close();   //close file
		
	}

	if (cnt == 19){
		cnt = 0;
	}
	
	Text score_text(std::string("Score: " + std::to_string(score)), font, 40);
	score_text.setFillColor(sf::Color::White);
	score_text.setPosition(1.f,1.f);
	score_text.move(8.f,5.f);
	window.draw(score_text);
	
	Text level_text(std::string("Level: " + std::to_string(level)), font, 40);
	level_text.setFillColor(sf::Color::White);
	level_text.setPosition(100.f,1.f);
	level_text.move(520.f,5.f);
	window.draw(level_text);
	
	Text health_text(std::string("Health: " + std::to_string(p->health/1000 + 1)), font, 40);
	health_text.setFillColor(sf::Color::White);
	health_text.setPosition(1.f,60.f);
	health_text.move(8.f,5.f);
	window.draw(health_text);
	
	Text lives_text(std::string("Lives: " + std::to_string(p->lives)), font, 40);
	lives_text.setFillColor(sf::Color::White);
	lives_text.setPosition(100.f,60.f);
	lives_text.move(520.f,5.f);
	window.draw(lives_text);
	
	window.display();  //Displying all the sprites
    }


}
