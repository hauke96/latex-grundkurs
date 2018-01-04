\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{meineklasse}[2000/01/01 Meine Klasse]

\RequirePackage[utf8]{inputenc}
\RequirePackage[T1]{fontenc}
\RequirePackage[ngerman]{babel}
\RequirePackage{lmodern}

\DeclareOption{sans}{
  \renewcommand*\familydefault{\sfdefault}
}

\ProcessOptions\relax

\LoadClass[a4paper,10pt]{scrartcl}

\endinput
