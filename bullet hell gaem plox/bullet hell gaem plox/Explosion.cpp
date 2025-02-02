#include "Explosion.h"


Explosion::Explosion(TextureManager& texMgr, sf::Vector2f pos_explo)
	: _frameSize(256, 256),
	_frameCount(8, 6),
	_currentFrame(0, 0),
	_frameDuration(0.0005f / 15.0f),
	_animationTime(0.0f)
{
	spr_explo.setPosition(pos_explo);
	spr_explo.setScale(0.3f, 0.3f);
	spr_explo.setTexture(texMgr.getRef("explosion"));
	spr_explo.setTextureRect(sf::IntRect(_currentFrame.x * _frameSize.x,
		_currentFrame.y*_frameSize.y, _frameSize.x, _frameSize.y));

	clock_explo.restart();
}


Explosion::~Explosion()
{
}

void Explosion::update(const sf::Time& elapsedTime)
{
	const float elapsedSeconds = elapsedTime.asSeconds();

	_animationTime += elapsedSeconds;
	if (_animationTime >= _frameDuration)
	{
		_currentFrame.x = ++_currentFrame.x % _frameCount.x;

		if (_currentFrame.x == 0)
			_currentFrame.y = ++_currentFrame.y % _frameCount.y;

		spr_explo.setTextureRect(sf::IntRect(_currentFrame.x * _frameSize.x, _currentFrame.y*_frameSize.y, _frameSize.x, _frameSize.y));

		_animationTime = 0.0f;
	}
	duration = clock_explo.getElapsedTime();
	timer = duration.asSeconds();
}

void Explosion::draw(sf::RenderWindow* window)
{
	window->draw(spr_explo);
}