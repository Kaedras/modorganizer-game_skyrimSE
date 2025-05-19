#include "../gameskyrimse.h"

#include <iostream>
#define STUB() std::cout << __FILE_NAME__ << ": " << __PRETTY_FUNCTION__ << ": STUB!\n"

static const QString appID = QStringLiteral("489830");

using namespace MOBase;

QString GameSkyrimSE::identifyGamePath() const
{
  QString result = parseSteamLocation(appID, gameDirectoryName());

  // Check Epic Games Manifests
  // AppName: ac82db5035584c7f8a2c548d98c86b2c
  //      AE Update: 5d600e4f59974aeba0259c7734134e27
  if (result.isEmpty()) {
    result = parseEpicGamesLocation(
        {"ac82db5035584c7f8a2c548d98c86b2c", "5d600e4f59974aeba0259c7734134e27"});
  }

  return result;
}

QString GameSkyrimSE::localAppFolder() const
{
  if (selectedVariant() == "GOG") {
    // todo: implement this case
    STUB();
    return "";
  }
  if (selectedVariant() == "Epic Games") {
    // todo: implement this case
    STUB();
    return "";
  }
  return GameGamebryo::localAppFolder(appID);
}
