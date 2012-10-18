#ifndef __GAME_ENGINE_HPP__
# define __GAME_ENGINE_HP__

# include <map>

namespace Sophie {

  template <typename Behaviour, typename MapHandler>
  class GameEngine : Behaviour {

  public:
    GameEngine() {
    }

    void Update() {
      this->Behaviour::Update();
    }

  private:
    MapHandler		_mapHandler;
  }

};

#endif
