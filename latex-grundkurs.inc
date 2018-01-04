\usepackage[utf8]{inputenc}
\usepackage[ngerman]{babel}
\usepackage{url}
\usepackage{minted}
\usepackage[absolute,overlay]{textpos}
\usepackage{lastpage}
\usepackage{listings}
\usepackage{color}
\usepackage{tikz}
\usepackage{pgf}
\usepackage{tabularx}

\usepackage{banyan-net}
\usepackage{hypercube-5D}

\usetikzlibrary{
	calc,
	intersections,
	through,
	positioning,
	hobby,
	automata,
	arrows}

\newcommand\pgfmathsinandcos[3]{%
    \pgfmathsetmacro#1{sin(#3)}%
    \pgfmathsetmacro#2{cos(#3)}%
}
\newcommand\LongitudePlane[3][current plane]{%
    \pgfmathsinandcos\sinEl\cosEl{#2} % elevation
    \pgfmathsinandcos\sint\cost{#3}   % azimuth
    \tikzset{#1/.estyle={cm={\cost,\sint*\sinEl,0,\cosEl,(0,0)}}}
}
\newcommand\LatitudePlane[3][current plane]{%
    \pgfmathsinandcos\sinEl\cosEl{#2} % elevation
    \pgfmathsinandcos\sint\cost{#3}   % latitude
    \pgfmathsetmacro\yshift{\cosEl*\sint}
    \tikzset{#1/.estyle={cm={\cost,0,0,\cost*\sinEl,(0,\yshift)}}} %
}
\newcommand\DrawLongitudeCircle[2][1]{
    \LongitudePlane{\angEl}{#2}
    \tikzset{current plane/.prefix style={scale=#1}}
    % angle of "visibility"
    \pgfmathsetmacro\angVis{atan(sin(#2)*cos(\angEl)/sin(\angEl))} %
    \draw[current plane] (\angVis:1) arc (\angVis:\angVis+180:1);
    \draw[current plane,dashed] (\angVis-180:1) arc (\angVis-180:\angVis:1);
}
\newcommand\DrawLatitudeCircle[2][1]{
    \LatitudePlane{\angEl}{#2}
    \tikzset{current plane/.prefix style={scale=#1}}
    \pgfmathsetmacro\sinVis{sin(#2)/cos(#2)*sin(\angEl)/cos(\angEl)}
    % angle of "visibility"
    \pgfmathsetmacro\angVis{asin(min(1,max(\sinVis,-1)))}
    \draw[current plane] (\angVis:1) arc (\angVis:-\angVis-180:1);
    \draw[current plane,dashed] (180-\angVis:1) arc (180-\angVis:\angVis:1);
}

\definecolor{pblue}{rgb}{0.13,0.13,1}
\definecolor{pgreen}{rgb}{0,0.5,0}
\definecolor{light-light-gray}{gray}{0.95}
\definecolor{myBlue}{rgb}{0,0.55,0.8}

\lstset{ %
	language=Java,   							% choose the language of the code
	basicstyle=\small\ttfamily,  				% the size of the fonts that are used for the code
	numbers=left,                   			% where to put the line-numbers
	numbersep=5pt,                  			% how far the line-numbers are from the code
	backgroundcolor=\color{light-light-gray},   % choose the background color. You must add
	frame=lrtb,           						% adds a frame around the code
	tabsize=4,          						% sets default tabsize to 2 spaces
	captionpos=b,           					% sets the caption-position to bottom
	breaklines=true,        					% sets automatic line breaking
	xleftmargin=1.5cm,							% space from the left paper edge
	commentstyle=\color{pgreen},
	keywordstyle=\color{pblue},
	literate=%
	    {Ö}{{\"O}}1
	    {Ä}{{\"A}}1
	    {Ü}{{\"U}}1
	    {ß}{{\ss}}1
	    {ü}{{\"u}}1
	    {ä}{{\"a}}1
	    {ö}{{\"o}}1
	    {~}{{\textasciitilde}}1
}

\input{extra/miniframescontrol}
\input{extra/latexcode}
\input{extra/patchfancyvrb}

\usetheme[compress]{Berlin}
\setbeamerfont{headline}{size=\large}
\setbeamerfont*{section in head/foot}{size=\tiny}
\setbeamertemplate{toc}{circle}
\setbeamertemplate{itemize subitem}[triangle] % if you want a triangle
\setbeamercovered{transparent}

%Für [Seite]/[Anzahl-Seiten] in der unteren rechten ecke
\newcommand*\oldmacro{}%
\let\oldmacro\insertshorttitle%
\renewcommand*\insertshorttitle
{
	\oldmacro\hfill%
	\thepage\,/\,\pageref{LastPage}
}

\usecolortheme[named=myBlue]{structure}

\newcommand{\slideheading}[1]{\textbf{#1}}
\newcommand{\TikZ}{Ti\textit{k}Z}
\newcommand{\bus}[4]{Ein Bus der Linie #1 Richtung #2 fährt von #3 um #4 ab.}

\beamertemplatenavigationsymbolsempty
