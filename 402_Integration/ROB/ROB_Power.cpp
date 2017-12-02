// Fill out your copyright notice in the Description page of Project Settings.

#include "ROB_Power.h"

ROB_Power::ROB_Power()
{
}

ROB_Power::~ROB_Power()
{
}

double ROB_Power::Power_Level(bool movement, double powerlevel, float dt) {
	intpower = 30*dt;
	motpower = 200*dt;
	if (movement){
		powerconsumed = motpower + intpower;
	}
	else {
		powerconsumed = intpower;
	}
	powerlevel = powerlevel - powerconsumed;
	return powerlevel;
};