COPY DreamGame\cmake-build-build-web\DreamGame.data docs
COPY DreamGame\cmake-build-build-web\DreamGame.js docs
COPY DreamGame\cmake-build-build-web\DreamGame.wasm docs
COPY DreamGame\cmake-build-build-web\DreamGame.html docs
DEL docs\old.html
RENAME docs\index.html old.html
RENAME docs\DreamGame.html index.html
pause