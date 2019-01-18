#pragma once

#include "skills.h"
#include "math.h"



namespace MyStrategy
{

	void goalkeeper(BeliefState *state, int botID)
	{
		Vec2D dpoint;
		Vec2D opp;
		//print("GoalKeeper\n");
		if ((state->ballPos.y > HALF_FIELD_MAXY / 2) && (state->ballPos.x < -HALF_FIELD_MAXX / 2))
		{ //portion1 
			dpoint.x = state->ballPos.x;
			dpoint.y = HALF_FIELD_MAXY / 2;
			Vec2D fpoint(0, HALF_FIELD_MAXY);
			Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
			if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 4 * BOT_BALL_THRESH)
				GoToPoint(botID, state, fpoint, PI / 2, true, true);
			else
				GoToPoint(botID, state, ballPoint, 0, false, true);
		}
		if ((state->ballPos.y < -HALF_FIELD_MAXY / 2) && (state->ballPos.x < -HALF_FIELD_MAXX / 2))
		{  //portion4
			// dpoint.x = state->ballPos.x;
			dpoint.y = -HALF_FIELD_MAXY / 2;
			dpoint.x = state->ballPos.x;
			//dpoint.y = state->ballPos.y;
		//	GoToPoint(botID,state, opp, -PI / 2, true, false);
			Vec2D fpoint(0, HALF_FIELD_MAXY);
			Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
			if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 4 * BOT_BALL_THRESH)
				GoToPoint(botID, state, fpoint, PI / 2, true, true);
			else
				GoToPoint(botID, state, ballPoint, 0, false, true);

		}
		if ((state->ballPos.x>-HALF_FIELD_MAXX / 2) && ((state->ballPos.y<HALF_FIELD_MAXY/2) || (state->ballPos.y>-HALF_FIELD_MAXY/2)))
		{//portion7&6
			// dpoint.x = -HALF_FIELD_MAXX / 2;
			Vec2D fpoint(state->homePos[2].x, state->homePos[2].y);
			Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
			dpoint.x = state->ballPos.x;
			// dpoint.y = state->ballPos.y;
			dpoint.y = state->ballPos.y;
			GoToPoint(botID, state, dpoint, PI / 2, false, false);
			if (Vec2D::distSq(state->homePos[1], state->ballPos) < 4 * BOT_BALL_THRESH)
				GoToPoint(botID, state, fpoint, PI / 2, true, false);
			else
				GoToPoint(botID, state, ballPoint, 0, false, true);

		}
		if ((state->ballPos.x<-HALF_FIELD_MAXX / 2) && ((state->ballPos.y<HALF_FIELD_MAXY/2) || (state->ballPos.y>-HALF_FIELD_MAXY/2)))
		{//portion2&3
			Vec2D fpoint(0, 0);
			Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
			GoToPoint(botID, state, opp, PI / 2, false, false);
			if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 4 * BOT_BALL_THRESH)
				GoToPoint(botID, state, fpoint, PI / 2, true, false);
			else
				GoToPoint(botID, state, ballPoint, 0, false, true);
		}
		if ((state->ballPos.x>-HALF_FIELD_MAXX / 2) && ((state->ballPos.y>HALF_FIELD_MAXY/2) || (state->ballPos.y<-HALF_FIELD_MAXY/2)))
		{//portion8&5
			Vec2D fpoint(HALF_FIELD_MAXY, 0);
			if (state->ballPos.y>HALF_FIELD_MAXY)
				Vec2D fpoint(HALF_FIELD_MAXY, 0);
			if (state->ballPos.y < -HALF_FIELD_MAXY)
				Vec2D fpoint(-HALF_FIELD_MAXY, 0);
			Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
			dpoint.x = state->ballPos.x;
			dpoint.y = state->ballPos.y;
			GoToPoint(botID, state, dpoint, PI / 2, false, false);
			if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 4 * BOT_BALL_THRESH)
				GoToPoint(botID, state, fpoint, PI / 2, true, false);
			else
				GoToPoint(botID, state, ballPoint, 0, false, true);
		}
		if (state->ballPos.x >0)
		{
			Vec2D dpoint;
			dpoint.y = -state->ballPos.y;
			if (state->ballPos.y > HALF_FIELD_MAXY / 2)
				dpoint.y = -HALF_FIELD_MAXY / 2;
			if (state->ballPos.y < -HALF_FIELD_MAXY / 2)
				dpoint.y = HALF_FIELD_MAXY / 2;
			dpoint.x = state->ballPos.x;
			GoToPoint(botID, state, dpoint, PI / 2, false, false);
			if (Vec2D::distSq(state->homePos[botID], state->ballPos) < 2 * BOT_BALL_THRESH)
			{
				GoToPoint(botID, state, dpoint, -PI / 4, false, false);
			}
		}
		//something's wrong here overrides with 1-8
		else
		{
			Vec2D  ballPoint(state->ballPos.x, state->ballPos.y);
			Vec2D dpoint;
			dpoint.x = -HALF_FIELD_MAXX + 1000;
			dpoint.y = state->ballPos.y;
			//nearest bot
			if (Vec2D::distSq(state->awayPos[2], state->ballPos) < 6*BOT_BALL_THRESH)
			{
				GoToPoint(botID, state, ballPoint, 0, false, true);
			}
			else
			{
				GoToPoint(botID, state, dpoint, 0, false, true);
			}
		}
		if (state->homePos[botID].x < -HALF_FIELD_MAXX+1000)
		{
			Vec2D dpoint;
			dpoint.y = state->ballPos.y;
			dpoint.x = -HALF_FIELD_MAXX + 2000;
			GoToPoint(botID, state, dpoint, PI / 2, true, false);
		}
		/*	Vec2D dpoint(OUR_GOAL_X + BOT_RADIUS + 250, state->ballPos.y);

			if (state->homePos[0].x>(OUR_GOAL_X + BOT_RADIUS + 250) || state->homePos[0].x<(OUR_GOAL_X + BOT_RADIUS + 350))
			dpoint.x = OUR_GOAL_X + BOT_RADIUS + 250;
			if (dpoint.y > OUR_GOAL_MAXY + 100)
			{
			dpoint.y = OUR_GOAL_MAXY + 100;
			}
			if (dpoint.y < OUR_GOAL_MINY - 100)
			{
			dpoint.y = OUR_GOAL_MINY - 100;
			}
			GoToPoint(botID, state, dpoint, PI / 2, true, false);

			if (state->homePos[0].y == OUR_GOAL_MAXY + 100 || state->homePos[0].y == OUR_GOAL_MINY - 100)
			{
			Vector2D<int> s1, s2;
			s1.y = state->homePos[0].y + 200;
			s1.x = state->homePos[0].x;
			s2.y = state->homePos[0].y - 200;
			s2.x = state->homePos[0].x;
			GoToPoint(botID, state, s1, PI / 2, true, false);
			if (state->homePos[0].y == s1.y)
			GoToPoint(botID, state, s2, PI / 2, true, false);
			else if (state->homePos[0].y == s2.y)
			GoToPoint(botID, state, dpoint, PI / 2, true, false);
			}
			*/
		/*Vec2D dpoint(OUR_GOAL_X + DBOX_HEIGHT, state->ballPos.y);
		dpoint.x = (-HALF_FIELD_MAXX);
		if (state->homePos[0].x>(OUR_GOAL_X + BOT_RADIUS + 250) || state->homePos[0].x<(OUR_GOAL_X + BOT_RADIUS + 350))
		dpoint.x = OUR_GOAL_X + BOT_RADIUS + 200;
		if (dpoint.y > OUR_GOAL_MAXY)
		{
		dpoint.y = OUR_GOAL_MAXY;
		}
		if (dpoint.y < OUR_GOAL_MINY)
		{
		dpoint.y = OUR_GOAL_MINY;
		}
		dpoint.y = state->ballPos.y;
		//dpoint.y += 400;
		//GoToPoint(botID, state, dpoint, PI / 2, false, false);
		//dpoint.y -= 800;
		//GoToPoint(botID, state, dpoint, PI / 2, false, false);
		//dpoint.y += 400;*/
		/*Spin(0, MAX_BOT_OMEGA);

		GoToPoint(botID, state, dpoint, PI / 2, false, false);
		if (state->homePos[0].x>(OUR_GOAL_X + BOT_RADIUS + 250) || state->homePos[0].x<(OUR_GOAL_X + BOT_RADIUS + 350))
		dpoint.x = OUR_GOAL_X + BOT_RADIUS + 250;
		GoToPoint(botID, state, dpoint, PI / 2, false, false);
		if ((state->ballPos.y > OPP_GOAL_MINY - 400) && (state->ballPos.y < OPP_GOAL_MINY + 400))
		{
		Vec2D fpoint(-HALF_FIELD_MAXX,-HALF_FIELD_MAXY/2 );
		Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
		if (Vec2D::distSq(state->homePos[0], state->ballPos) < 4 * BOT_BALL_THRESH)
		GoToPoint(botID, state, fpoint, PI / 2, true, false);
		}
		if ((state->ballPos.y > OPP_GOAL_MAXY - 400) && (state->ballPos.y < OPP_GOAL_MAXY + 400))
		{
		Vec2D fpoint(-HALF_FIELD_MAXX, HALF_FIELD_MAXY / 2);
		Vec2D ballPoint(state->ballPos.x, state->ballPos.y);
		if (Vec2D::distSq(state->homePos[0], state->ballPos) < 4 * BOT_BALL_THRESH)
		GoToPoint(botID, state, fpoint, PI / 2, true, false);
		}
		*/
		
	}
}