#pragma once
#include "PowerUp.h"
#include "PowerUpManager.h"

class Game
{
public:
	explicit Game( const Window& window );
	Game( const Game& other ) = delete;
	Game& operator=( const Game& other ) = delete;
	~Game();

	void Update( float elapsedSec );
	void Draw( );

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e );
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e );
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e );
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e );
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e );

private:
	// DATA MEMBERS
	Window m_Window;
	Point2f m_MousePos{};
	Rectf m_Destroyer{ 0.0f,0.0f,20.0f,20.0f };

	const size_t m_Rows{ 3 };
	const size_t m_Cols{ 4 };
	const size_t m_MaxNrItems{ m_Rows * m_Cols };
	std::vector<Point2f> m_Centers;
	std::vector< PowerUp::Type >m_Types;
	PowerUpManager* m_pTestedManager{ nullptr };
	size_t m_TestedManagerSize{ 0 };

	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( );

	void TestWithoutDrawing( );
	void InitTestWithDrawing( );

	void TestSize( PowerUpManager* pTestedManager, size_t expectedSize );
	void TestAddingItems( PowerUpManager* pTestedManager, const std::vector<Point2f>& centers, const std::vector< PowerUp::Type >& types );
	void TestHittingItems( PowerUpManager* pTestedManager, const std::vector<Point2f>& centers );
	void TestHittingItem( PowerUpManager* pTestedManager, const Rectf& destroyer );
	void TestHittingCircle(  std::vector<Point2f>& centers, const Rectf& destroyer );

	void ShowTestMessage( ) const;
	void ShowNrItems( ) const;

	void MoveDestroyer( const Point2f& newCenter );
	void DrawDestroyer( ) const;
	void DrawCircles( const std::vector<Point2f>& centers, const std::vector< PowerUp::Type >& types ) const;

};