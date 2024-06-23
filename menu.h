
#include "game.cpp"
class Menu{
public:

	Sprite menu_background;
	Texture menu_texture;
	bool exit;

	Menu();

	void display_menu();

	void sort(int arr[], int size);

};
