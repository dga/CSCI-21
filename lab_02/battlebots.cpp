/****************************
 * Name: Daniel G. Arnold   *
 * Course: CSCI 21          *
 * Project: Lab 2           *
 * Filename: battlebots.cpp *
 ****************************/

#include "arenaui.h"

int main()
{
	ArenaUI* ui = new ArenaUI();

	ui->go();

	delete ui;
	ui = NULL;

	return 0;
}
