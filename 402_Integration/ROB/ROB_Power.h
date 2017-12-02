// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MYPROJECT5_API ROB_Power
{
public:
	ROB_Power();
	~ROB_Power();
	double motpower;
	double intpower;
	bool movement;
	double powerlevel;
	double powerconsumed;
	float dt;

	double ROB_Power::Power_Level(bool movement, double powerlevel, float dt);
};
