#include <CLI/CLI.hpp>
#include "drive/driveManager.h"

int main(int argc, char* argv[]) {
    CLI::App app{"A small program that mounts network drives", "externmnt"};
    argv = app.ensure_utf8(argv);

    CLI11_PARSE(app, argc, argv);

    DriveManager driveManager {};

    return 0;
}
