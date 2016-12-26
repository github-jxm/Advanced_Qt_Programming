Advanced Qt Programming by Mark Summerfield

ISBN: 978-0321635907

All the example programs and modules are copyright (c) Qtrac Ltd. 2009-10.
They are free software: you can redistribute them and/or modify them
under the terms of the GNU General Public License as published by the
Free Software Foundation, either version version 3 of the License, or
(at your option) any later version. They are provided for educational
purposes and are distributed in the hope that they will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public Licenses (in file gpl-3.0.txt) for more details.

All the book's examples are designed to be educational, and many are
also designed to be useful. I hope that you find them helpful, and are
perhaps able to use some of them as starting points for your own
projects.

Most of the icons and sounds are from KDE (The `K' Desktop Environment),
and come under KDE's LGPL license. (Visit http:///www.kde.org for more
information.)

The entire set of examples can be built in one go by running qmake and
then make (or nmake) in their top level directory---the directory that
contains examples.pro.

Note that the Alt_Key library's documentation is here:
http://www.qtrac.eu/alt_key_api.html

Here is the list of programs referred to in the book grouped by chapter:

Chapter 1: Hybrid Desktop/Internet Applications
    weathertrayicon
    rsspanel
    browserwindow
    nyrbviewer
    matrixquiz

Chapter 2: Audio and Video
    moviejingle
    playmusic
    playvideo

Chapter 3: Model/View Table Models
    zipcodes1
    zipcodes2

Chapter 4: Model/View Tree Models
    timelog1
    timelog2

Chapter 5: Model/View Delegates
    folderview
    timelog1
    zipcodes1

Chapter 6: Model/View Views
    censusvisualizer
    tiledlistview

Chapter 7: Threading with QtConcurrent
    image2image
    numbergrid

Chapter 8: Threading with QThread
    crossfader
    findduplicates

Chapter 9: Creating Rich Text Editors
    findduplicates
    xmledit
    timelog1
    textedit

Chapter 10: Creating Rich Text Documents
    outputsampler

Chapter 11: Creating Graphics/View Windows
    petridish1

Chapter 12: Creating Graphics/View Scenes
    pagedesigner1

Chapter 13: The Animation and State Machine Frameworks
    finddialog
    petridish2
    pagedesigner2

STOP PRESS: I have now added an alternative implementation of the
BoxItem::mouseMoveEvent() handler for Page Designer. By default the
original implementation is used for pagedesigner1 and the alternative
one for pagedesigner2.

CREDITS: Thanks to Rémi Faitout for fixes to make the examples build
with MSVC8.
