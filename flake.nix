{
  inputs = { nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable"; };

  outputs = { nixpkgs, ... }:
    let
      forAllSystems = nixpkgs.lib.genAttrs [ "x86_64-linux" ];
      pkgs' = forAllSystems (system: nixpkgs.legacyPackages.${system});
    in {
      devShells = forAllSystems (system:
        let pkgs = pkgs'.${system};
        in with pkgs; {
          default = mkShell {
            packages = [ ];

            buildInputs = with xorg; [ libX11 libXinerama libXft ];

            # shellHook = ''
            #   # .
            # '';
          };
        });
    };
}
