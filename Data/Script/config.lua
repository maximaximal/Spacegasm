-- window resolution
	WindowX = 800;
  WindowY = 500;
	fullscreen = false;
-- debug mode
	debug = {
		active = false;
		TextureManager = false;
		SoundManager = false;
		FontManager = false;
	};
-- OS
-- 0 = Linux64;
-- 1 = Linux32;
-- 2 = Windows;
	OS = 0;
-- extreme Mode (Sets the levelup-points from 200 to 20)
	extremeMode = false;			--RESTRICTED
-- Screensaver Mode
	ScreenSaverMode = false;
-- number of stars in the background (-1 = automatic)
	backgroundStarsCount = -1;
-- background style
	backgroundStarsStyle = 1;
-- Delay between key presses to trigger a double click/tab (in milliseconds)
	doubleTapSpeed = 0; --Deactivated because it sucks xD - Standard Value would be around 180 though
-- Shoot Rate (Delay between a shot - in milliseconds)
	shootRate = 150;			--RESTRICTED
-- Start Laser
-- 1 = RED
-- 2 = BLUE
-- 3 = GREEN
-- 4 = MAGENTA
-- The startLaserLevel is a value from 1 to 4 (1 is normal, 4 is the best)
	startLaser = 1;				--RESTRICTED
	startLaserLevel = 1;			--RESTRICTED
-- Sound Configuration
	backgroundMusic = true;
	backgroundMucicVolume = 23;
	gameSounds = true;
	gameSoundsVolume = 64;
-- Physic variables
	Forces = {
		normalMove = 1500;		--RESTRICTED
		shiftMove = 3000;		--RESTRICTED
		quickMove = 1200;		--RESTRICTED
	}
