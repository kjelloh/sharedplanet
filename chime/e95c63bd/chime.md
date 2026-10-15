# Todo: Consider to document how (and where) my brew upgrade llvm from 17.0.5 to 18.1.6 went?

```#e95c63bd``` *As of 2024-06-05 16:43*

[mail plain/text](mail.txt)

{% raw %}
I still find that keeping my LLVM and Clang++ up-to-date on my macOS requires me to delve into opaque procedures with unclear result but at least using Brew I can just try the approach I documented to work last time so I do this on this time around again :)

==&gt; Also see "[Todo: Consider to document how (and where) my brew upgrade llvm from 16.0.2 to 16.0.6 went?](../b93f6a23/chime.md)"

1) It seems I should be able to do (<https://formulae.brew.sh/formula/llvm> )?

==&gt; It seems the command 'brew upgrade llvm' succeeded and installed to **/usr/local/Cellar/llvm/18.1.6**

> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit % **brew upgrade llvm**  
> Running \`brew update --auto-update\`...  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/portable-ruby/portable-ruby/blobs/sha256:5c86a23e0e3caee1a4cfd958ed7d50a38e752ebaf2e7c5717e5c8eabaa6e9f12>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Pouring portable-ruby-3.3.2.el_capitan.bottle.tar.gz**  
> ==&gt; **Auto-updated Homebrew!**

> Updated 3 taps (freecad/freecad, homebrew/core and homebrew/cask).

> ==&gt; **New Formulae**  
> actions-batch deadfinder g-ls kin mariadb@11.2 overtls rtabmap tfautomv  
> ansible-creator descope gcc@13 kiota mdformat parsedmarc ruby@3.2 tmt  
> apache-flink-cdc dhall-toml gimmecert ktfmt mdsh pass-import rust-parallel tofuenv  
> appwrite dillo git-grab kubecolor mihomo pawk rustcat tomlplusplus  
> argc direwolf git-split-diffs kubectl-cnpg mlx pdfrip rustls-ffi traefik@2  
> asmfmt displayplacer gitu kubectl-rook-ceph mmdbinspect pedump scala@3.3 typstfmt  
> autobrr dissent glasskube kubernetes-cli@1.29 moon phodav scnlib uni-algo  
> autotrace doltgres glbinding@2 kubeshark morpheus pivit seam urlscan  
> basti dotslash gnmic kubetui msieve pkl senpai uutils-diffutils  
> beakerlib dotter go-size-analyzer kuto mtm pnpm@8 sherlock uv  
> beancount-language-server dpcmd go@1.21 kuzu mubeng podlet sigi valkey  
> bigquery-emulator drogon godap lexido navidrome podman-tui soapyremote vedic  
> bluez edbrowse gorilla-cli liblc3 ncmdump policy_sentry solo2-cli veilid  
> bootterm edgevpn gptscript libnsbmp neosync prjtrellis span-lite vexctl  
> bpftop envio greenmask libnsgif netaddr promptfoo sqlboiler vfox  
> c-blosc2 erlang_ls halp liborigin netsurf-buildsystem proto srgn vrc-get  
> c3c espeak-ng haproxy@2.8 libscfg nextdns protoc-gen-js ssh3 vulkan-profiles  
> c4core fastapi helm-docs libspelling nmail purr sshpass vulkan-volk  
> cahute fern-api helm-ls libsql noseyparker qshell steamguard-cli wasmedge  
> cargo-fuzz ffmpeg@6 hopscotch-map libtickit nowplaying-cli rage stripe-cli whisperkit-cli  
> cargo-llvm-cov flawz iamb libvirt-python npm-check-updates ratchet stripe-mock wstunnel  
> cargo-sweep flowpipe icloudpd libwapcaplet nvtop rathole sugarjar xcode-build-server  
> cekit forbidden ignite limesuite ocaml@4 rattler-build sui yara-x  
> chainhook freecad/freecad/boost-python3.11 ingress2gateway llama.cpp ocicl rawdog superfile yatas  
> chisel-tunnel freecad/freecad/coin3d_py310 inlyne llvm@17 oils-for-unix redict sysaidmin yo  
> cidr freecad/freecad/fc_bundle jnv logdy oj redress tartufo zigmod  
> cloudflare-cli4 freecad/freecad/freecad@0.20.2_py310 jot lsusb-laniksj open-simh retire task@2 zipkin  
> cmake-language-server freecad/freecad/numpy@1.26.4_py310 jsontoolkit mactop openfa river taskopen  
> cotp freecad/freecad/pybind11_py310 jtbl [magic-wormhole.rs](http://magic-wormhole.rs) openjph robin-map tenv  
> csvlens freecad/freecad/pyside2@5.15.11_py310 k8sgpt manim opensca-cli ronn-ng terrapin-scanner  
> dalfox freecad/freecad/shiboken2@5.15.11_py310 kconf mantra overarch rsyncy texi2mdoc  
> ==&gt; **New Casks**  
> 1password-cli@1 font-besley font-et-book font-iosevka-ss17 font-miltonian font-noto-serif-gurmukhi font-rubik-maps font-waptia  
> 1password-cli@beta font-beth-ellen font-euphoria-script font-iosevka-ss18 font-miltonian-tattoo font-noto-serif-hebrew font-rubik-marker-hatch font-warnes  
> 1password@7 font-bevan font-everson-mono font-iosevka-term-nerd-font font-mina font-noto-serif-hentaigana font-rubik-maze font-water-brush  
> 1password@beta font-bhavuka font-ewert font-iosevka-term-slab-nerd-font font-mingzat font-noto-serif-hk font-rubik-microbe font-waterfall  
> 1password@nightly font-bhutuka-expanded-one font-exo font-ipaexfont font-miniver font-noto-serif-jp font-rubik-mono-one font-wavefont  
> ableton-live-intro@11 font-big-shoulders-display font-exo-2 font-ipafont font-miriam-libre font-noto-serif-kannada font-rubik-moonrocks font-wellfleet  
> ableton-live-lite@11 font-big-shoulders-inline-display font-expletus-sans font-ipamjmincho font-miriam-mono-clm font-noto-serif-khitan-small-script font-rubik-one font-wendy-one  
> ableton-live-standard@11 font-big-shoulders-inline-text font-explora font-iranian-sans font-mirza font-noto-serif-khmer font-rubik-pixels font-whisper  
> ableton-live-suite@10 font-big-shoulders-stencil-display font-ezra-sil font-iranian-serif font-miss-fajardose font-noto-serif-khojki font-rubik-puddles font-windsong  
> ableton-live-suite@11 font-big-shoulders-stencil-text font-fahkwang font-irish-grover font-mitr font-noto-serif-kr font-rubik-scribble font-wire-one  
> acreom font-big-shoulders-text font-fairfax font-island-moments font-mochiy-pop-one font-noto-serif-lao font-rubik-spray-paint font-wix-madefor-display  
> adguard-vpn@nightly font-bigblue-terminal-nerd-font font-familjen-grotesk font-istok-web font-mochiy-pop-p-one font-noto-serif-makasar font-rubik-storm font-wix-madefor-text  
> adguard@nightly font-bigelow-rules font-fandol font-italiana font-modak font-noto-serif-malayalam font-rubik-vinyl font-work-sans  
> aerial@beta font-bigshot-one font-fantasque-sans-mono font-italianno font-modern-antiqua font-noto-serif-myanmar font-rubik-wet-paint font-workbench  
> affinity-designer@1 font-bilbo font-fantasque-sans-mono-nerd-font font-itim font-mogra font-noto-serif-np-hmong font-ruda font-xanh-mono  
> affinity-photo@1 font-bilbo-swash-caps font-fantasque-sans-mono-noloopk font-jaapokki font-mohave font-noto-serif-nyiakeng-puachue-hmong font-rufina font-xits  
> affinity-publisher@1 font-biorhyme font-fanwood-text font-jacquard-12 font-moirai-one font-noto-serif-old-uyghur font-ruge-boogie font-xkcd  
> alcom font-biorhyme-expanded font-farro font-jacquard-12-charted font-molengo font-noto-serif-oriya font-ruluko font-xkcd-script  
> alfred@4 font-birthstone font-farsan font-jacquard-24 font-molle font-noto-serif-ottoman-siyaq font-rum-raisin font-yaldevi  
> amie font-birthstone-bounce font-fascinate font-jacquard-24-charted font-mona-sans font-noto-serif-sc font-ruslan-display font-yaldevi-colombo  
> amneziavpn font-biryani font-fascinate-inline font-jacquarda-bastarda-9 font-monaspace font-noto-serif-sinhala font-russo-one font-yanone-kaffeesatz  
> anchor-wallet font-bitstream-vera font-faster-one font-jacquarda-bastarda-9-charted font-monaspace-nerd-font font-noto-serif-tamil font-ruthie font-yantramanav  
> android-studio-preview@beta font-bitstream-vera-sans-mono-nerd-font font-fasthand font-jacques-francois font-monda font-noto-serif-tangut font-ruwudu font-yarndings-12  
> android-studio-preview@canary font-bitter font-fauna-one font-jacques-francois-shadow font-monocraft font-noto-serif-tc font-rye font-yarndings-12-charted  
> anka-build-cloud-controller font-bitter-ht font-faune font-jaini font-monocraft-nerd-font font-noto-serif-telugu font-sacramento font-yarndings-20  
> anka-build-cloud-registry font-biz-udgothic font-faustina font-jaini-purva font-monofett font-noto-serif-thai font-sahitya font-yarndings-20-charted  
> anythingllm font-biz-udmincho font-federant font-jaldi font-monofur-for-powerline font-noto-serif-tibetan font-sail font-yatra-one  
> apidog-europe font-biz-udpgothic font-federo font-jaro font-monofur-nerd-font font-noto-serif-toto font-saira font-yellowtail  
> aqua font-biz-udpmincho font-felipa font-jeju-gothic font-monoid font-noto-serif-vithkuqi font-saira-condensed font-yeon-sung  
> arctic font-black-and-white-picture font-fenix font-jeju-hallasan font-monoid-nerd-font font-noto-serif-yezidi font-saira-extra-condensed font-yeseva-one  
> arduino-ide@nightly font-black-han-sans font-festive font-jeju-myeongjo font-monoisome font-noto-traditional-nushu font-saira-semi-condensed font-yesteryear  
> arm-performance-libraries font-black-ops-one font-figtree font-jersey-10 font-monomaniac-one font-noto-znamenny-musical-notation font-saira-stencil-one font-yinmar  
> arturia-software-center font-blackout font-finger-paint font-jersey-10-charted font-mononoki font-nova-cut font-salsa font-yomogi  
> automattic-texts font-blaka font-finlandica font-jersey-15 font-mononoki-nerd-font font-nova-flat font-sanchez font-young-serif  
> azure-data-studio@insiders font-blaka-hollow font-fira-code font-jersey-15-charted font-monoton font-nova-mono font-sancreek font-yrsa  
> bbedit@14 font-blaka-ink font-fira-code-nerd-font font-jersey-20 font-monsieur-la-doulaise font-nova-oval font-sankofa-display font-ysabeau  
> beyond-compare@beta font-blex-mono-nerd-font font-fira-mono font-jersey-20-charted font-montaga font-nova-round font-sans-forgetica font-ysabeau-infant  
> bias-fx font-blinker font-fira-mono-for-powerline font-jersey-25 font-montagu-slab font-nova-script font-sansation font-ysabeau-office  
> bitbox font-blokk-neue font-fira-mono-nerd-font font-jersey-25-charted font-montecarlo font-nova-slim font-sansita font-ysabeau-sc  
> blender@lts font-bm font-fira-sans font-jetbrains-mono font-montez font-nova-square font-sansita-one font-yuji-boku  
> blitz-gg font-bodoni-moda font-fira-sans-condensed font-jetbrains-mono-nerd-font font-montserrat font-ntr font-sansita-swashed font-yuji-hentaigana-akari  
> blockstream-green font-bodoni-moda-sc font-fira-sans-extra-condensed font-jf-open-huninn font-montserrat-alternates font-numans font-sarabun font-yuji-hentaigana-akebono  
> boltai font-bokor font-firago font-jim-nightshade font-montserrat-subrayada font-nunito font-sarala font-yuji-mai  
> brave-browser@beta font-bona-nova font-firge font-joan font-moo-lah-lah font-nunito-sans font-sarasa-gothic font-yuji-syuku  
> brave-browser@dev font-bona-nova-sc font-firgenerd font-jockey-one font-mooli font-nuosu-sil font-sarina font-yusei-magic  
> brave-browser@nightly font-bonbon font-fjalla-one font-jolly-lodger font-moon-dance font-ocr font-sarpanch font-zcool-kuaile  
> brightintosh font-bonheur-royale font-fjord-one font-jomhuria font-moul font-odibee-sans font-sassy-frass font-zcool-qingke-huangyou  
> buckets@beta font-boogaloo font-flamenco font-jomolhari font-moulpali font-odor-mean-chey font-satisfy font-zcool-xiaowei  
> bugdom2 font-borel font-flavors font-joscelyn font-mountains-of-christmas font-office-code-pro font-sauce-code-pro-nerd-font font-zed-mono  
> cahier font-bowlby-one font-fleur-de-leah font-josefin-sans font-mouse-memoirs font-offside font-sawarabi-gothic font-zed-mono-nerd-font  
> calibrite-profiler font-bowlby-one-sc font-flow-block font-josefin-slab font-mplus font-ofl-sorts-mill-goudy-tt font-sawarabi-mincho font-zed-sans  
> canon-ufrii-driver font-braah-one font-flow-circular font-jost font-mplus-nerd-font font-oi font-scada font-zen-antique  
> capcut font-brawler font-flow-rounded font-joti-one font-mr-bedfort font-ojuju font-scheherazade font-zen-antique-soft  
> carbon-copy-cloner@5 font-bree-serif font-foldit font-jsmath-cmbx10 font-mr-dafoe font-old-standard-tt font-scheherazade-new font-zen-dots  
> carbon-copy-cloner@6 font-bricolage-grotesque font-fondamento font-jsmath-cmex10 font-mr-de-haviland font-oldenburg font-schibsted-grotesk font-zen-kaku-gothic-antique  
> cardo-update font-briem-hand font-fontawesome font-jsmath-cmmi10 font-mrs-saint-delafield font-ole font-schoolbell font-zen-kaku-gothic-new  
> chatgpt font-brill font-fontdiner-swanky font-jsmath-cmr10 font-mrs-sheppards font-oleo-script font-scope-one font-zen-kurenaido  
> chime font-bruno-ace font-forum font-jsmath-cmsy10 font-ms-madi font-oleo-script-swash-caps font-seaweed-script font-zen-loop  
> chromedriver@beta font-bruno-ace-sc font-foundation-icons font-jsmath-cmti10 font-mukta font-onest font-secular-one font-zen-maru-gothic  
> cleanclip font-brygada-1918 font-foundry-sterling font-jua font-mukta-mahee font-oooh-baby font-sedan font-zen-old-mincho  
> cleanupbuddy font-bubblegum-sans font-fragment-mono font-judson font-mukta-malar font-open-dyslexic font-sedan-sc font-zen-tokyo-zoo  
> clearvpn font-bubbler-one font-francois-one font-julee font-mukta-vaani font-open-dyslexic-nerd-font font-sedgwick-ave font-zeyada  
> core-tunnel font-buda font-frank-ruhl-libre font-juliamono font-mukti-narrow font-open-iconic font-sedgwick-ave-display font-zhi-mang-xing  
> corretto@11 font-buenard font-fraunces font-julius-sans-one font-mulish font-open-sans font-sen font-zhudou-sans  
> corretto@17 font-bukyvede-bold font-freckle-face font-junction font-murecho font-open-sans-hebrew font-send-flowers font-zhuque-fangsong  
> corretto@21 font-bukyvede-italic font-fredericka-the-great font-junge font-museo font-open-sans-hebrew-condensed font-sevillana font-zilla-slab  
> corretto@8 font-bukyvede-regular font-fredoka font-junicode font-museomoderno font-oppo-sans font-seymour-one font-zilla-slab-highlight  
> creality-print font-bungee font-free-mono-tengwar font-jura font-my-soul font-optician-sans font-sf-arabic freeshow  
> crystaldiffract font-bungee-color font-freefont font-just-another-hand font-myanmar-sans-pro font-oranienbaum font-sf-armenian fujifilm-x-raw-studio  
> crystalviewer font-bungee-hairline font-freehand font-just-me-again-down-here font-mynerve font-orbit font-sf-compact galaxybudsclient  
> darkmodebuddy font-bungee-inline font-freeman font-k2d font-myrica font-orbitron font-sf-georgian garmin-basecamp  
> dash@6 font-bungee-outline font-fresca font-kablammo font-myricam font-oregano font-sf-hebrew geekbench-ml  
> db-browser-for-sqlcipher@nightly font-bungee-shade font-frijole font-kadwa font-mystery-quest font-orelega-one font-sf-mono geogebra@5  
> db-browser-for-sqlite@nightly font-bungee-spice font-fruktur font-kaisei-decol font-n-gage font-orienta font-sf-mono-for-powerline gimp@dev  
> deadbeef@nightly font-butcherman font-fugaz-one font-kaisei-harunoumi font-nabla font-original-surfer font-sf-pro gitbutler  
> deelay font-butterfly-kids font-fuggles font-kaisei-opti font-namdhinggo font-ostrich-sans font-shadows-into-light github@beta  
> defold@alpha font-cabin font-fuzzy-bubbles font-kaisei-tokumin font-nanum-brush-script font-oswald font-shadows-into-light-two godot@3  
> defold@beta font-cabin-condensed font-fzfangsong-z02 font-kaiso font-nanum-gothic font-otomanopee-one font-shalimar godspeed  
> discord@canary font-cabin-sketch font-fzkai-z03 font-kalam font-nanum-gothic-coding font-outfit font-shantell-sans google-chrome@beta  
> discord@development font-cactus-classical-serif font-fzshusong-z01 font-kalnia font-nanum-myeongjo font-over-the-rainbow font-shanti google-chrome@canary  
> discord@ptb font-caesar-dressing font-fzxiaobiaosong-b05 font-kalnia-glaze font-nanum-pen-script font-overlock font-share google-chrome@dev  
> dnsmonitor font-cagliostro font-gabarito font-kameron font-narnoor font-overlock-sc font-share-tech google-japanese-ime@dev  
> dolphin@beta font-cairo font-gabriela font-kanit font-national-park font-overpass font-share-tech-mono gpg-suite@nightly  
> dolphin@dev font-cairo-play font-gaegu font-kanjistrokeorders font-nats font-overpass-mono font-shippori-antique graalvm-jdk@17  
> domzilla-caffeine font-cal-sans font-gafata font-kantumruy-pro font-neonderthaw font-overpass-nerd-font font-shippori-antique-b1 graalvm-jdk@21  
> dosbox-staging font-caladea font-gajraj-one font-kapakana font-nerko-one font-overused-grotesk font-shippori-mincho halloy  
> dotnet-sdk@preview font-calistoga font-galada font-karantina font-neucha font-ovo font-shippori-mincho-b1 hancom-docs  
> dotnet@preview font-calligraffitti font-galdeano font-karla font-neuton font-oxanium font-shizuru hapigo  
> dropbox@beta font-cambay font-galindo font-karla-tamil-inclined font-new-rocker font-oxygen font-shojumaru heynote  
> easydevo font-cambo font-gamja-flower font-karla-tamil-upright font-new-tegomin font-oxygen-mono font-short-stack hhkb-studio  
> egovframedev font-camingocode font-gandhi-sans font-karma font-new-york font-pacifico font-shrikhand hopper-disassembler  
> elecom-mouse-util font-candal font-gantari font-katibeh font-news-cycle font-padauk font-shure-tech-mono-nerd-font hyper@canary  
> element@nightly font-cantarell font-gasoek-one font-kaushan-script font-newsreader font-padyakke-expanded-one font-siemreap ia-markdown-dictionary  
> elephas@beta font-cantata-one font-gayathri font-kavivanar font-nico-moji font-palanquin font-sigmar ia-presenter  
> emacs@nightly font-cantora-one font-geist font-kavoon font-niconne font-palanquin-dark font-sigmar-one ibkr  
> emacs@pretest font-caprasimo font-geist-mono font-kawkab-mono font-nikukyu font-palette-mosaic font-signika imazing-profile-editor  
> emby font-capriola font-geist-mono-nerd-font font-kay-pho-du font-nimbus-sans-l font-pangolin font-signika-negative inso@beta  
> endless-sky-high-dpi font-caramel font-gelasio font-kdam-thmor-pro font-niramit font-paprika font-signika-negative-sc insomnia@alpha  
> ente-auth font-carattere font-gemunu-libre font-keania-one font-nixie-one font-parisienne font-signika-sc insomnium  
> figma@beta font-cardo font-genjyuugothic font-kelly-slab font-nobile font-passero-one font-silkscreen instantview  
> firefox@beta font-carlito font-genjyuugothic-l font-kenia font-nokora font-passion-one font-simonetta intellij-idea@eap  
> firefox@cn font-carme font-genjyuugothic-x font-khand font-norican font-passions-conflict font-simple-line-icons ireal-pro  
> firefox@developer-edition font-carrois-gothic font-genos font-khmer font-nosifer font-pathway-extreme font-single-day irpf2024  
> firefox@esr font-carrois-gothic-sc font-genryumin font-khula font-nosifer-caps font-pathway-gothic-one font-sintony istat-menus@5  
> firefox@nightly font-carter-one font-gensekigothic font-khyay font-notable font-patrick-hand font-sirin-stencil iterm2@beta  
> fixkey font-cascadia-code font-gensenrounded font-kimberella font-nothing-you-could-do font-patrick-hand-sc font-sitara iterm2@nightly  
> flox font-cascadia-code-nf font-genshingothic font-kings font-noticia-text font-pattaya font-six-caps jamie  
> focusrite-control-2 font-cascadia-code-pl font-gentium-basic font-kirang-haerang font-noto-color-emoji font-patua-one font-sixtyfour jan  
> folding-at-home@beta font-cascadia-mono font-gentium-book-basic font-kite-one font-noto-color-emoji-compat-test font-pavanam font-skranji java@beta  
> font-0xproto font-cascadia-mono-nf font-gentium-book-plus font-kiwi-maru font-noto-emoji font-paytone-one font-slabo-13px jordanbaird-ice  
> font-0xproto-nerd-font font-cascadia-mono-pl font-gentium-plus font-klee-one font-noto-kufi-arabic font-peddana font-slabo-27px jslegendre-themeengine  
> font-3270 font-caskaydia-cove-nerd-font font-genwanmin font-knewave font-noto-mono font-peralta font-slackey julia@lts  
> font-3270-nerd-font font-caskaydia-mono-nerd-font font-genyogothic font-ko-pub-batang font-noto-mono-for-powerline font-permanent-marker font-slackside-one julia@nightly  
> font-437-plus font-castoro font-genyomin font-kodchasan font-noto-music font-petemoss font-smiley-sans juxtacode  
> font-abeezee font-castoro-titling font-geo font-kode-mono font-noto-naskh-arabic font-petit-formal-script font-smokum jyutping  
> font-abel font-catamaran font-geologica font-koh-santepheap font-noto-naskh-arabic-ui font-petrona font-smooch kaleidoscope@2  
> font-abhaya-libre font-caudex font-georama font-koho font-noto-nastaliq-urdu font-phetsarath font-smooch-sans kaleidoscope@3  
> font-aboreto font-caveat font-georgia font-kokoro font-noto-nerd-font font-philosopher font-smythe keepassxc@beta  
> font-aboriginal-sans font-caveat-brush font-geostar font-kolker-brush font-noto-rashi-hebrew font-photonico-code font-sn-pro keepassxc@snapshot  
> font-aboriginal-serif font-cedarville-cursive font-geostar-fill font-konkhmer-sleokchher font-noto-sans font-phudu font-sniglet keka@beta  
> font-abril-fatface font-ceviche-one font-germania-one font-kosugi font-noto-sans-adlam font-piazzolla font-snippet keyboard-cowboy  
> font-abyssinica-sil font-chakra-petch font-gfs-didot font-kosugi-maru font-noto-sans-adlam-unjoined font-piedra font-snowburst-one kit  
> font-academicons font-changa font-gfs-neohellenic font-kotta-one font-noto-sans-anatolian-hieroglyphs font-pigmo00 font-sofadi-one kitty@nightly  
> font-aclonica font-changa-one font-gideon-roman font-koulen font-noto-sans-arabic font-pigmo01 font-sofia lando@edge  
> font-acme font-chango font-gidole font-kranky font-noto-sans-arabic-ui font-pinyon-script font-sofia-sans libreoffice-still  
> font-actor font-chapbook font-gidugu font-kreon font-noto-sans-armenian font-pirata-one font-sofia-sans-condensed libreoffice-still-language-pack  
> font-adamina font-charis-sil font-gilbert font-kristi font-noto-sans-avestan font-pixelify-sans font-sofia-sans-extra-condensed lightburn  
> font-adinatha-tamil-brahmi font-charm font-gilda-display font-krona-one font-noto-sans-balinese font-plangothic font-sofia-sans-semi-condensed limitless  
> font-adlam-display font-charmonman font-girassol font-krub font-noto-sans-bamum font-plaster font-solitreo little-snitch@4  
> font-adobe-blank font-charter font-give-you-glory font-kufam font-noto-sans-bassa-vah font-platypi font-solway little-snitch@5  
> font-advent-pro font-chathura font-glass-antiqua font-kulim-park font-noto-sans-batak font-play font-sometype-mono local@beta  
> font-afacad font-chau-philomene-one font-glegoo font-kumar-one font-noto-sans-bengali font-playball font-song-myung lookaway  
> font-african-sans font-chela-one font-gloock font-kumbh-sans font-noto-sans-bengali-ui font-playfair font-sono loungy  
> font-african-serif font-chelsea-market font-gloria-hallelujah font-kurale font-noto-sans-bhaiksuki font-playfair-display font-sonsie-one lunarbar  
> font-agave-nerd-font font-chenla font-glory font-la-belle-aurore font-noto-sans-brahmi font-playfair-display-sc font-sora lw-scanner  
> font-agbalumo font-chenyuluoyan font-glow-sans-j-compressed font-labrada font-noto-sans-buginese font-playpen-sans font-sorts-mill-goudy lyricsfinder  
> font-agdasima font-cherish font-glow-sans-j-condensed font-lacquer font-noto-sans-buhid font-playwrite-au-nsw font-souliyo mac-mouse-fix@2  
> font-aguafina-script font-cherry-bomb-one font-glow-sans-j-extended font-laila font-noto-sans-canadian-aboriginal font-playwrite-au-qld font-source-code-pro macfuse@dev  
> font-ahuramzda font-cherry-cream-soda font-glow-sans-j-normal font-lakki-reddy font-noto-sans-carian font-playwrite-au-sa font-source-code-pro-for-powerline macloggerdx@beta  
> font-aileron font-cherry-swash font-glow-sans-j-wide font-lalezar font-noto-sans-caucasian-albanian font-playwrite-au-tas font-source-sans-3 mailmate@beta  
> font-akatab font-chewy font-glow-sans-sc-compressed font-lancelot font-noto-sans-chakma font-playwrite-au-vic font-source-serif-4 markedit  
> font-akaya-kanadaka font-chiayi-city font-glow-sans-sc-condensed font-langar font-noto-sans-cham font-playwrite-br font-space-grotesk metarename  
> font-akaya-telivigala font-chicle font-glow-sans-sc-extended font-langdon font-noto-sans-cherokee font-playwrite-ca font-space-mono metavideo  
> font-akronim font-chilanka font-glow-sans-sc-normal font-last-resort font-noto-sans-chorasmian font-playwrite-co font-space-mono-nerd-font mi@beta  
> font-aksara-bali-galang font-chiron-hei-hk font-glow-sans-sc-wide font-last-resort-high-efficiency font-noto-sans-cjk font-playwrite-de-grund font-special-elite microsoft-edge@beta  
> font-akshar font-chiron-sung-hk font-glow-sans-tc-compressed font-lateef font-noto-sans-cjk-hk font-playwrite-de-la font-spectral microsoft-edge@dev  
> font-aladin font-chivo font-glow-sans-tc-condensed font-latin-modern font-noto-sans-cjk-jp font-playwrite-de-sas font-spectral-sc microsoft-openjdk@11  
> font-alata font-chivo-mono font-glow-sans-tc-extended font-latin-modern-math font-noto-sans-cjk-kr font-playwrite-de-va font-spicy-rice microsoft-openjdk@17  
> font-alatsi font-chocolate-classical-sans font-glow-sans-tc-normal font-lato font-noto-sans-cjk-sc font-playwrite-es font-spinnaker microsoft-teams@classic  
> font-albert-sans font-chokokutai font-glow-sans-tc-wide font-lavishly-yours font-noto-sans-cjk-tc font-playwrite-es-deco font-spirax mixxx@snapshot  
> font-albertella font-chomsky font-gluten font-league-gothic font-noto-sans-coptic font-playwrite-fr-moderne font-splash monal@beta  
> font-aldrich font-chonburi font-gnu-unifont font-league-mono font-noto-sans-cuneiform font-playwrite-fr-trad font-spleen mongodb-compass@beta  
> font-alef font-church-slavonic font-go font-league-script font-noto-sans-cypriot font-playwrite-gb-j font-spline-sans mono-mdk-for-visual-studio  
> font-alegreya font-cica font-go-mono-nerd-font font-league-spartan font-noto-sans-cypro-minoan font-playwrite-gb-s font-spline-sans-mono motion  
> font-alegreya-sans font-cinzel font-goblin-one font-leckerli-one font-noto-sans-deseret font-playwrite-id font-squada-one msty  
> font-alegreya-sans-sc font-cinzel-decorative font-gochi-hand font-ledger font-noto-sans-devanagari font-playwrite-ie font-square-peg mullvadvpn@beta  
> font-alegreya-sc font-clear-sans font-gohufont-nerd-font font-lekton font-noto-sans-devanagari-ui font-playwrite-in font-sree-krushnadevaraya mumble@snapshot  
> font-aleo font-clicker-script font-goldman font-lekton-nerd-font font-noto-sans-display font-playwrite-is font-sriracha mumuplayer  
> font-alex-brush font-climate-crisis font-golos-text font-lemon font-noto-sans-duployan font-playwrite-it-moderna font-srisakdi naps2  
> font-alexandria font-cochineal font-gorditas font-lemonada font-noto-sans-egyptian-hieroglyphs font-playwrite-it-trad font-staatliches navicat-premium@15  
> font-alfa-slab-one font-coda font-gothic-a1 font-lemonada-vf-beta font-noto-sans-elbasan font-playwrite-mx font-stalemate navigraph-charts  
> font-alice font-code-new-roman-nerd-font font-gotu font-lexend font-noto-sans-elymaic font-playwrite-ng-modern font-stalinist-one navigraph-simlink  
> font-alike font-code2002 font-goudy-bookletter-1911 font-lexend-deca font-noto-sans-ethiopic font-playwrite-nl font-stardos-stencil nessus  
> font-alike-angular font-codicon font-gowun-batang font-lexend-exa font-noto-sans-georgian font-playwrite-no font-stick netnewswire@beta  
> font-alkalami font-codystar font-gowun-dodum font-lexend-giga font-noto-sans-glagolitic font-playwrite-nz font-stick-no-bills nightshade  
> font-alkatra font-coelacanth font-graduate font-lexend-mega font-noto-sans-gothic font-playwrite-pl font-stint-ultra-condensed notes-better  
> font-allan font-coiny font-grand-hotel font-lexend-peta font-noto-sans-grantha font-playwrite-pt font-stint-ultra-expanded notesollama  
> font-allerta font-combo font-grandiflora-one font-lexend-tera font-noto-sans-gujarati font-playwrite-ro font-stix nperf  
> font-allerta-stencil font-comfortaa font-grandstander font-lexend-zetta font-noto-sans-gujarati-ui font-playwrite-sk font-stix-two-math nrfutil  
> font-allison font-comforter font-grape-nuts font-liberation font-noto-sans-gunjala-gondi font-playwrite-tz font-stix-two-text nx-studio  
> font-allura font-comforter-brush font-gravitas-one font-liberation-mono-for-powerline font-noto-sans-gurmukhi font-playwrite-us-modern font-stoke obs-backgroundremoval  
> font-almarai font-comic-mono font-great-vibes font-liberation-nerd-font font-noto-sans-gurmukhi-ui font-playwrite-us-trad font-strait obs@beta  
> font-almendra font-comic-neue font-grechen-fuemen font-libertinus font-noto-sans-hanifi-rohingya font-playwrite-vn font-strong october  
> font-almendra-display font-comic-sans-ms font-grenze font-libre-barcode-128 font-noto-sans-hanunoo font-playwrite-za font-style-script ollama  
> font-almendra-sc font-comic-shanns-mono-nerd-font font-grenze-gotisch font-libre-barcode-128-text font-noto-sans-hatran font-plemol-jp font-stylish ollamac  
> font-alumni-sans font-coming-soon font-grey-qo font-libre-barcode-39 font-noto-sans-hebrew font-plemol-jp-hs font-sudo olympus  
> font-alumni-sans-collegiate-one font-comme font-griffy font-libre-barcode-39-extended font-noto-sans-hk font-plemol-jp-nf font-sue-ellen-francisco omegat@latest  
> font-alumni-sans-collegiate-one-sc font-commissioner font-gruppo font-libre-barcode-39-extended-text font-noto-sans-imperial-aramaic font-plus-jakarta-sans font-suez-one opencat  
> font-alumni-sans-inline-one font-commit-mono font-gudea font-libre-barcode-39-text font-noto-sans-indic-siyaq-numbers font-podkova font-sulphur-point openemu@experimental  
> font-alumni-sans-pinstripe font-commit-mono-nerd-font font-gugi font-libre-barcode-ean13-text font-noto-sans-inscriptional-pahlavi font-podkova-vf-beta font-sumana openra-playtest  
> font-amarante font-computer-modern font-gulzar font-libre-baskerville font-noto-sans-inscriptional-parthian font-poetsen-one font-sunflower openscad@snapshot  
> font-amaranth font-conakry font-gupter font-libre-bodoni font-noto-sans-javanese font-poiret-one font-sunshiney openshot-video-editor@daily  
> font-amatic-sc font-concert-one font-gurajada font-libre-caslon-display font-noto-sans-jp font-poller-one font-supermercado-one openthesaurus-deutsch  
> font-amethysta font-condiment font-gwendolyn font-libre-caslon-text font-noto-sans-kaithi font-poltawski-nowy font-sura opera-crypto@developer  
> font-amiko font-consolas-for-powerline font-habibi font-libre-franklin font-noto-sans-kannada font-poly font-suranna opera@beta  
> font-amiri font-constructium font-hachi-maru-pop font-licorice font-noto-sans-kannada-ui font-pompiere font-suravaram oracle-jdk@17  
> font-amiri-quran font-content font-hack font-life-savers font-noto-sans-kawi font-ponnala font-suwannaphum oracle-jdk@21  
> font-amita font-contrail-one font-hack-nerd-font font-liga-comic-mono font-noto-sans-kayah-li font-pontano-sans font-swanky-and-moo-moo outfox  
> font-amstelvar-alpha font-convergence font-hackgen font-ligature-symbols font-noto-sans-kharoshthi font-poor-story font-symbols-only-nerd-font overlayed  
> font-anaheim font-cookie font-hackgen-nerd font-lilex font-noto-sans-khmer font-poppins font-syncopate paragon-extfs@11  
> font-andada-pro font-cooper-hewitt font-hahmlet font-lilex-nerd-font font-noto-sans-khmer-ui font-poppins-latin font-syne parallels@12  
> font-andagii font-copse font-halant font-lilita-one font-noto-sans-khojki font-poprumcute font-syne-mono parallels@13  
> font-andale-mono font-corben font-hammersmith-one font-lily-script-one font-noto-sans-khudawadi font-port-lligat-sans font-syne-tactile parallels@14  
> font-andika font-corinthia font-han-nom-a font-limelight font-noto-sans-kr font-port-lligat-slab font-tac-one parallels@15  
> font-andron-scriptor-web font-cormorant font-hanalei font-linden-hill font-noto-sans-lao font-porter-sans-block font-tai-heritage-pro parallels@16  
> font-anek-bangla font-cormorant-garamond font-hanalei-fill font-linefont font-noto-sans-lao-looped font-potta-one font-tajawal parallels@17  
> font-anek-devanagari font-cormorant-infant font-hanamina font-linux-biolinum font-noto-sans-lao-ui font-powerline-symbols font-takaoex parallels@18  
> font-anek-gujarati font-cormorant-sc font-handjet font-linux-libertine font-noto-sans-lepcha font-pragati-narrow font-tangerine pdf-expert@beta  
> font-anek-gurmukhi font-cormorant-unicase font-handlee font-lisu-bosa font-noto-sans-limbu font-praise font-tapestry pecunia  
> font-anek-kannada font-cormorant-upright font-hanken-grotesk font-literata font-noto-sans-linear-a font-prata font-taprom pgadmin3  
> font-anek-latin font-courgette font-hannari font-liu-jian-mao-cao font-noto-sans-linear-b font-preahvihear font-tauri phocus  
> font-anek-malayalam font-courier-new font-hanuman font-livvic font-noto-sans-lisu font-press-start-2p font-taviraj phoenix-code  
> font-anek-odia font-courier-prime font-happy-monkey font-lobster font-noto-sans-lycian font-pretendard font-teachers picoscope@beta  
> font-anek-tamil font-courier-prime-code font-harano-aji font-lobster-two font-noto-sans-lydian font-pretendard-jp font-teko pile  
> font-anek-telugu font-courier-prime-medium-and-semi-bold font-harmattan font-lohit font-noto-sans-mahajani font-pretendard-std font-tektur playcover-community@beta  
> font-angkor font-courier-prime-sans font-hasklig font-lohit-bengali font-noto-sans-malayalam font-pridi font-telex postico@1  
> font-anka-coder font-cousine font-hasklug-nerd-font font-lohit-tamil font-noto-sans-malayalam-ui font-princess-sofia font-tenali-ramakrishna postman@canary  
> font-annapurna-sil font-cousine-nerd-font font-headland-one font-londrina-outline font-noto-sans-mandaic font-prociono font-tengwar-formal-csur posture-pal  
> font-annie-use-your-telescope font-coustard font-heavy-data-nerd-font font-londrina-shadow font-noto-sans-manichaean font-profont-nerd-font font-tengwar-telcontar powershell@preview  
> font-anonymice-nerd-font font-covered-by-your-grace font-hedvig-letters-sans font-londrina-sketch font-noto-sans-marchen font-profontx font-tenor-sans presonus-universal-control  
> font-anonymice-powerline font-cozette font-hedvig-letters-serif font-londrina-solid font-noto-sans-masaram-gondi font-proggy-clean-tt-nerd-font font-terminess-ttf-nerd-font prettyclean  
> font-anonymous-pro font-crafty-girls font-heebo font-long-cang font-noto-sans-math font-prompt font-terminus processing@3  
> font-anta font-creepster font-henny-penny font-lora font-noto-sans-mayan-numerals font-prosto-one font-tex-gyre-adventor propresenter@beta  
> font-antic font-creepster-caps font-hepta-slab font-love-light font-noto-sans-medefaidrin font-protest-guerrilla font-tex-gyre-bonum proton-mail  
> font-antic-didone font-crete-round font-hermeneus-one font-love-ya-like-a-sister font-noto-sans-meetei-mayek font-protest-revolution font-tex-gyre-bonum-math qbittorrent@lt20  
> font-antic-slab font-crimson-pro font-hermit font-loved-by-the-king font-noto-sans-mende-kikakui font-protest-riot font-tex-gyre-chorus qdirstat  
> font-antinoou font-crimson-text font-herr-von-muellerhoff font-lovers-quarrel font-noto-sans-meroitic font-protest-strike font-tex-gyre-cursor qgis@ltr  
> font-anton font-croissant-one font-hi-melody font-luckiest-guy font-noto-sans-miao font-proza-libre font-tex-gyre-heros qlzipinfo  
> font-anton-sc font-crushed font-hina-mincho font-luculent font-noto-sans-modi font-pt-mono font-tex-gyre-pagella qt-creator@dev  
> font-antonio font-cubic-11 font-hind font-lugrasimo font-noto-sans-mongolian font-pt-sans font-tex-gyre-pagella-math quick-app-ide  
> font-anuphan font-cuprum font-hind-colombo font-lumanosimo font-noto-sans-mono font-pt-sans-caption font-tex-gyre-schola quicktune  
> font-anybody font-cute-font font-hind-guntur font-lunasima font-noto-sans-mono-cjk-hk font-pt-sans-narrow font-tex-gyre-schola-math quiet  
> font-aoboshi-one font-cutive font-hind-jalandhar font-lusitana font-noto-sans-mono-cjk-jp font-pt-serif font-tex-gyre-termes reader  
> font-ar-one-sans font-cutive-mono font-hind-kochi font-lustria font-noto-sans-mono-cjk-kr font-pt-serif-caption font-tex-gyre-termes-math reflector@2  
> font-arapey font-d2coding font-hind-madurai font-luxurious-roman font-noto-sans-mono-cjk-sc font-public-sans font-text-me-one requestly  
> font-arbutus font-d2coding-nerd-font font-hind-mysuru font-luxurious-script font-noto-sans-mono-cjk-tc font-puppies-play font-texturina roam  
> font-arbutus-slab font-daddy-time-mono-nerd-font font-hind-siliguri font-lxgw-bright font-noto-sans-mro font-puritan font-thabit royal-tsx@beta  
> font-architects-daughter font-dai-banna-sil font-hind-vadodara font-lxgw-bright-gb font-noto-sans-multani font-purple-purse font-tharlon rstudio@daily  
> font-architype-renner font-damion font-holtwood-one-sc font-lxgw-bright-tc font-noto-sans-myanmar font-pushster font-thasadith safari-technology-preview  
> font-archivo font-dancing-script font-homemade-apple font-lxgw-fasmartgothic font-noto-sans-myanmar-ui font-qahiri font-the-girl-next-door sakura  
> font-archivo-black font-danfo font-homenaje font-lxgw-heartserif font-noto-sans-n-ko font-quando font-the-nautigal salt  
> font-archivo-narrow font-dangrek font-honk font-lxgw-neoxihei font-noto-sans-nabataean font-quantico font-tiejili-sc screaming-frog-log-file-analyser  
> font-are-you-serious font-darker-grotesque font-hubballi font-lxgw-neozhisong font-noto-sans-nag-mundari font-quattrocento font-tienne screenmemory  
> font-aref-ruqaa font-darumadrop-one font-hubot-sans font-lxgw-wenkai font-noto-sans-nandinagari font-quattrocento-sans font-tillana screens-assist  
> font-aref-ruqaa-ink font-darwin font-humor-sans font-lxgw-wenkai-gb font-noto-sans-new-tai-lue font-questrial font-tilt-neon segger-ozone  
> font-arial font-dashicons font-hurmit-nerd-font font-lxgw-wenkai-lite font-noto-sans-newa font-quicksand font-tilt-prism semeru-jdk-open@11  
> font-arial-black font-david-clm font-hurricane font-lxgw-wenkai-mono-tc font-noto-sans-nko font-quintessential font-tilt-warp semeru-jdk-open@17  
> font-arima font-david-libre font-hyppolit font-lxgw-wenkai-tc font-noto-sans-nko-unjoined font-qwigley font-times-new-roman semeru-jdk-open@21  
> font-arimo font-dawning-of-a-new-day font-ia-writer-duo font-lxgw-zhenkai font-noto-sans-nushu font-qwitcher-grypen font-times-newer-roman semeru-jdk-open@8  
> font-arimo-nerd-font font-days-one font-ia-writer-mono font-m-plus-1 font-noto-sans-ogham font-racing-sans-one font-timmana senabluetoothdevicemanager  
> font-arizonia font-decovar-alpha font-ia-writer-quattro font-m-plus-1-code font-noto-sans-ol-chiki font-radio-canada font-tinos shadow-bot  
> font-ark-pixel-10px-monospaced font-dejavu font-iansui font-m-plus-1p font-noto-sans-old-hungarian font-radio-canada-big font-tinos-nerd-font shadow@beta  
> font-ark-pixel-10px-proportional font-dejavu-sans-mono-for-powerline font-ibarra-real-nova font-m-plus-2 font-noto-sans-old-italic font-radley font-tiny5 signal@beta  
> font-ark-pixel-12px-monospaced font-dejavu-sans-mono-nerd-font font-ibm-plex font-m-plus-code-latin font-noto-sans-old-north-arabian font-rajdhani font-tiro-bangla simpletex  
> font-ark-pixel-12px-proportional font-dekko font-ibm-plex-mono font-ma-shan-zheng font-noto-sans-old-permic font-rakkas font-tiro-devanagari-hindi singlecrystal  
> font-ark-pixel-16px-monospaced font-dela-gothic-one font-ibm-plex-sans font-macondo font-noto-sans-old-persian font-raleway font-tiro-devanagari-marathi sketch@beta  
> font-ark-pixel-16px-proportional font-delicious-handrawn font-ibm-plex-sans-arabic font-macondo-swash-caps font-noto-sans-old-sogdian font-raleway-dots font-tiro-devanagari-sanskrit skype@preview  
> font-armata font-delius font-ibm-plex-sans-condensed font-mada font-noto-sans-old-south-arabian font-ramabhadra font-tiro-gurmukhi slack@beta  
> font-arsenal font-delius-swash-caps font-ibm-plex-sans-devanagari font-madimi-one font-noto-sans-old-turkic font-ramaraja font-tiro-kannada slicer@preview  
> font-arsenal-sc font-delius-unicase font-ibm-plex-sans-hebrew font-magra font-noto-sans-oriya font-rambla font-tiro-tamil smcfancontrol@beta  
> font-artifika font-della-respira font-ibm-plex-sans-jp font-maiden-orange font-noto-sans-oriya-ui font-rammetto-one font-tiro-telugu sonarr@beta  
> font-arvo font-delugia-book font-ibm-plex-sans-kr font-maitree font-noto-sans-osage font-rampart-one font-titan-one sonos-s1-controller  
> font-arya font-delugia-complete font-ibm-plex-sans-thai font-major-mono-display font-noto-sans-osmanya font-ranchers font-titillium sourcetree@beta  
> font-asap font-delugia-mono-complete font-ibm-plex-sans-thai-looped font-makinas4 font-noto-sans-pahawh-hmong font-rancho font-titillium-web starnet2  
> font-asap-condensed font-delugia-mono-powerline font-ibm-plex-serif font-mako font-noto-sans-palmyrene font-ranga font-togalite stashpad  
> font-asar font-delugia-powerline font-iceberg font-mali font-noto-sans-pau-cin-hau font-rasa font-tomorrow steinberg-activation-manager  
> font-asset font-denk-one font-iceland font-mallanna font-noto-sans-phags-pa font-rationale font-tourney streammusic  
> font-assistant font-devicons font-icomoon font-mamelon font-noto-sans-phagspa font-ravi-prakash font-trade-winds sublime-merge@dev  
> font-astloch font-devonshire font-im-fell-double-pica font-mandali font-noto-sans-phoenician font-readex-pro font-train-one sublime-text@dev  
> font-asul font-dhurjati font-im-fell-double-pica-sc font-manjari font-noto-sans-psalter-pahlavi font-recursive font-trebuchet-ms surge@4  
> font-athiti font-dhyana font-im-fell-dw-pica font-manrope font-noto-sans-rejang font-recursive-code font-trirong svp  
> font-atkinson-hyperlegible font-didact-gothic font-im-fell-dw-pica-sc font-mansalva font-noto-sans-runic font-recursive-mono-nerd-font font-trispace taccy  
> font-atma font-digital-numbers font-im-fell-english font-manuale font-noto-sans-samaritan font-red-hat-display font-trocchi telegram-desktop@beta  
> font-atomic-age font-digohweli-old-do font-im-fell-english-sc font-maple font-noto-sans-saurashtra font-red-hat-mono font-trochut temurin@11  
> font-aubrey font-diphylleia font-im-fell-french-canon font-marcellus font-noto-sans-sc font-red-hat-text font-truculenta temurin@17  
> font-audiowide font-diplomata font-im-fell-french-canon-sc font-marcellus-sc font-noto-sans-sharada font-red-rose font-trykker temurin@19  
> font-aurulent-sans-mono-nerd-font font-diplomata-sc font-im-fell-great-primer font-marck-script font-noto-sans-shavian font-redacted font-tsukimi-rounded temurin@20  
> font-autour-one font-dm-mono font-im-fell-great-primer-sc font-margarine font-noto-sans-siddham font-redacted-script font-tt2020 temurin@21  
> font-average font-dm-sans font-im-fell-types font-marhey font-noto-sans-signwriting font-reddit-mono font-tuffy temurin@8  
> font-average-mono font-dm-serif-display font-im-writing-nerd-font font-markazi-text font-noto-sans-sinhala font-reddit-sans font-tulpen-one termius@beta  
> font-average-sans font-dm-serif-text font-imbue font-marko-one font-noto-sans-sinhala-ui font-reddit-sans-condensed font-turret-road theiaide  
> font-averia-gruesa-libre font-do-hyeon font-iming font-marmelad font-noto-sans-sogdian font-redhat font-twilio-sans-mono threema@beta  
> font-averia-libre font-dokdo font-impact font-martel font-noto-sans-sora-sompeng font-redressed font-twinkle-star thunderbird@beta  
> font-averia-sans-libre font-domine font-imperial-script font-martel-sans font-noto-sans-soyombo font-reem-kufi font-twitter-color-emoji thunderbird@daily  
> font-averia-serif-libre font-donegal-one font-imprima font-martian-mono font-noto-sans-sundanese font-reem-kufi-fun font-typographer-woodcut-initials-one timelapze  
> font-awesome-terminal-fonts font-dongle font-inclusive-sans font-martian-mono-nerd-font font-noto-sans-syloti-nagri font-reem-kufi-ink font-ubuntu toneprint  
> font-azeret-mono font-doppio-one font-inconsolata font-marvel font-noto-sans-symbols font-reenie-beanie font-ubuntu-condensed topaz-photo-ai  
> font-azonix font-dorsa font-inconsolata-dz-for-powerline font-masinahikan font-noto-sans-symbols-2 font-reggae-one font-ubuntu-mono tor-browser@alpha  
> font-b612 font-dosis font-inconsolata-for-powerline font-masinahikan-dene font-noto-sans-syriac font-rem font-ubuntu-mono-derivative-powerline transmission@nightly  
> font-b612-mono font-dotgothic16 font-inconsolata-for-powerline-bold font-mate font-noto-sans-syriac-eastern font-rethink-sans font-ubuntu-mono-nerd-font truhu  
> font-babylonica font-doulos-sil font-inconsolata-g font-mate-sc font-noto-sans-syriac-estrangela font-revalia font-ubuntu-nerd-font tsh@13  
> font-bacasime-antique font-dr-sugiyama font-inconsolata-g-for-powerline font-material-design-icons-webfont font-noto-sans-syriac-western font-rhodium-libre font-ubuntu-sans tunnelblick@beta  
> font-bad-script font-dream-han-sans font-inconsolata-go-nerd-font font-material-icons font-noto-sans-tagalog font-ribeye font-ubuntu-sans-mono typora@dev  
> font-bagel-fat-one font-droid-sans-mono-for-powerline font-inconsolata-lgc font-material-symbols font-noto-sans-tagbanwa font-ribeye-marrow font-ubuntu-sans-nerd-font ugg  
> font-bahiana font-droid-sans-mono-nerd-font font-inconsolata-lgc-nerd-font font-maven-pro font-noto-sans-tai-le font-ricty-diminished font-uchen upscayl  
> font-bahianita font-duru-sans font-inconsolata-nerd-font font-maven-pro-vf-beta font-noto-sans-tai-tham font-righteous font-udev-gothic utm@beta  
> font-bai-jamjuree font-dynalight font-inder font-mclaren font-noto-sans-tai-viet font-risque font-udev-gothic-nf viable  
> font-bakbak-one font-dynapuff font-indie-flower font-mea-culpa font-noto-sans-takri font-road-rage font-ultra vimcal  
> font-ballet font-eagle-lake font-infini font-meddon font-noto-sans-tamil font-roboto font-unbounded virtualbox@6  
> font-baloo font-east-sea-dokdo font-ingrid-darling font-medievalsharp font-noto-sans-tamil-supplement font-roboto-condensed font-uncial-antiqua virtualbox@beta  
> font-baloo-2 font-eater font-inika font-medula-one font-noto-sans-tamil-ui font-roboto-flex font-undefined-medium virtualbuddy@beta  
> font-baloo-bhai-2 font-eb-garamond font-inknut-antiqua font-meera-inimai font-noto-sans-tangsa font-roboto-mono font-underdog virtualdj  
> font-baloo-bhaijaan-2 font-ebh font-input font-megrim font-noto-sans-tc font-roboto-mono-for-powerline font-unica-one visual-studio-code@insiders  
> font-baloo-bhaina-2 font-economica font-inria font-meie-script font-noto-sans-telugu font-roboto-mono-nerd-font font-unifrakturcook vivaldi@snapshot  
> font-baloo-chettan-2 font-eczar font-inria-sans font-meltho font-noto-sans-telugu-ui font-roboto-serif font-unifrakturmaguntia vlc@nightly  
> font-baloo-da-2 font-edlo font-inria-serif font-mengshen-regular font-noto-sans-thaana font-roboto-slab font-unkempt vscodium@insiders  
> font-baloo-paaji-2 font-edu-nsw-act-foundation font-inspiration font-menlo-for-powerline font-noto-sans-thai font-rochester font-unlock wakatime  
> font-baloo-tamma-2 font-edu-qld-beginner font-instrument-sans font-meow-script font-noto-sans-thai-looped font-rock-3d font-unna warcraft-logs-uploader  
> font-baloo-tammudu-2 font-edu-sa-beginner font-instrument-serif font-merge-one font-noto-sans-thai-ui font-rock-salt font-updock wave  
> font-baloo-thambi-2 font-edu-tas-beginner font-intel-one-mono font-merienda font-noto-sans-tibetan font-rocknroll-one font-urbanist weasis  
> font-balsamiq-sans font-edu-vic-wa-nt-beginner font-inter font-merriweather font-noto-sans-tifinagh font-rokkitt font-urw-base35 wezterm@nightly  
> font-balthazar font-edwin font-inter-tight font-merriweather-sans font-noto-sans-tirhuta font-rokkitt-vf-beta font-vampiro-one whatsapp@beta  
> font-bangers font-el-messiri font-intone-mono-nerd-font font-mervale-script font-noto-sans-ugaritic font-romanesco font-varela whatsapp@legacy  
> font-barlow font-electrolize font-iosevka font-meslo-for-powerlevel10k font-noto-sans-vai font-ronde font-varela-round whoozle-android-file-transfer@nightly  
> font-barlow-condensed font-elice-digital-baeum font-iosevka-aile font-meslo-for-powerline font-noto-sans-vithkuqi font-ropa-sans font-varta wifiman  
> font-barlow-semi-condensed font-elsie font-iosevka-comfy font-meslo-lg font-noto-sans-wancho font-rosario font-vast-shadow wine@devel  
> font-barriecito font-elsie-swash-caps font-iosevka-curly font-meslo-lg-dz font-noto-sans-warang-citi font-rosarivo font-vazirmatn wine@staging  
> font-barrio font-elstobd font-iosevka-curly-slab font-meslo-lg-nerd-font font-noto-sans-yi font-rouge-script font-verdana wins  
> font-basic font-emblema-one font-iosevka-etoile font-metal font-noto-sans-zanabazar-square font-rounded-mplus font-vesper-libre wiso-steuer-2024  
> font-baskervville font-emilys-candy font-iosevka-nerd-font font-metal-mania font-noto-serif font-routed-gothic font-viaoda-libre wljs-notebook  
> font-baskervville-sc font-encode-sans font-iosevka-slab font-metamorphous font-noto-serif-ahom font-rowdies font-vibes wordpresscom-studio  
> font-battambang font-encode-sans-condensed font-iosevka-ss01 font-metrophobic font-noto-serif-armenian font-rozha-one font-vibur xact  
> font-baumans font-encode-sans-expanded font-iosevka-ss02 font-metropolis font-noto-serif-balinese font-rubik font-victor-mono xampp@7  
> font-bayon font-encode-sans-sc font-iosevka-ss03 font-miama font-noto-serif-bengali font-rubik-80s-fade font-victor-mono-nerd-font xcodepilot  
> font-be-vietnam-pro font-encode-sans-semi-condensed font-iosevka-ss04 font-miao-unicode font-noto-serif-cjk font-rubik-beastly font-vidaloka xmind@beta  
> font-beau-rivage font-encode-sans-semi-expanded font-iosevka-ss05 font-michroma font-noto-serif-cjk-hk font-rubik-broken-fax font-viga yandex-music  
> font-bebas-neue font-engagement font-iosevka-ss06 font-micro-5 font-noto-serif-cjk-jp font-rubik-bubbles font-vina-sans yass  
> font-belanosima font-englebert font-iosevka-ss07 font-micro-5-charted font-noto-serif-cjk-kr font-rubik-burned font-voces yes24-ebook  
> font-belgrano font-enriqueta font-iosevka-ss08 font-migmix-1m font-noto-serif-cjk-sc font-rubik-dirt font-volkhov youlean-loudness-meter  
> font-bellefair font-envy-code-r font-iosevka-ss09 font-migmix-1p font-noto-serif-cjk-tc font-rubik-distressed font-vollkorn zed@preview  
> font-belleza font-envy-code-r-nerd-font font-iosevka-ss10 font-migmix-2m font-noto-serif-devanagari font-rubik-doodle-shadow font-vollkorn-sc znote  
> font-bellota font-ephesis font-iosevka-ss11 font-migmix-2p font-noto-serif-display font-rubik-doodle-triangles font-voltaire zotero@beta  
> font-bellota-text font-epilogue font-iosevka-ss12 font-migu-1c font-noto-serif-dogra font-rubik-gemstones font-vt323 zulu@11  
> font-benchnine font-erica-one font-iosevka-ss13 font-migu-1m font-noto-serif-ethiopic font-rubik-glitch font-vujahday-script zulu@17  
> font-benne font-escumasia font-iosevka-ss14 font-migu-1p font-noto-serif-georgian font-rubik-glitch-pop font-waiting-for-the-sunrise zulu@21  
> font-bentham font-esteban font-iosevka-ss15 font-migu-2m font-noto-serif-grantha font-rubik-iso font-wallpoet zulu@8  
> font-berkshire-swash font-estonia font-iosevka-ss16 font-milonga font-noto-serif-gujarati font-rubik-lines font-walter-turncoat  
> ==&gt; **Deleted Installed Formulae**  
> **tbb@2020 ****✘**

> You have **118** outdated formulae and **2** outdated casks installed.

> ==&gt; **Upgrading 1 outdated package:**  
> **llvm 17.0.5 -&gt; 18.1.6**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/llvm/manifests/18.1.6>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching dependencies for llvm: ****mpdecimal****, ****ca-certificates****, ****openssl@3****, ****readline****, ****sqlite****, ****xz****, ****python@3.12****, ****z3** **and ****zstd**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/mpdecimal/manifests/4.0.0-1>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****mpdecimal**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/mpdecimal/blobs/sha256:266a3f517227bb9f3806b18313c3b8a33688f9659e5001751e15f1f38538dacc>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/ca-certificates/manifests/2024-03-11>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****ca-certificates**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/ca-certificates/blobs/sha256:cab828953672906e00a8f25db751977b8dc4115f021f8dfe82b644ade03dacdb>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/openssl/3/manifests/3.3.0-1>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****openssl@3**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/openssl/3/blobs/sha256:f5b70155f3fdbf574843741924758ca05fc996263e348660ac817e75052dacf9>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/readline/manifests/8.2.10>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****readline**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/readline/blobs/sha256:3633320dce51662036ea90acfc9adf5bb5e6f1dca7dbdb539839736129c474b0>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/sqlite/manifests/3.46.0>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****sqlite**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/sqlite/blobs/sha256:9117120ebe7933b7a3c588d62bc804d90f575175c7fe082eadee257fa51727e6>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/xz/manifests/5.4.6>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****xz**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/xz/blobs/sha256:9195af5a2fcbecf42267f4738254a3a58257d2a303fa6c63ec09eb4def7f7c1e>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/python/3.12/manifests/3.12.3>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****python@3.12**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/python/3.12/blobs/sha256:75ae75d6dafd805e42ba57d823d4dd8ffdbfde545ccc0340a2229ec183619274>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/z3/manifests/4.13.0>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****z3**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/z3/blobs/sha256:c6e139509b1ca4abdebf498a3373546dd14a645c4c56c5ad37092616c6ae2874>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/zstd/manifests/1.5.6>**  
> ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****zstd**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/zstd/blobs/sha256:b5099f7c339af2fff89af3a844a004b35aba400787ef71e1db6e856889f56557>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Fetching ****llvm**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/llvm/blobs/sha256:30eaec79147745d01e446ce681884e73cedfd472320a26181d5f7887e51348ab>**  
> #=#=- # # #=O#- # # ######################################################################################################################################################################################################################################################### 100.0%  
> ==&gt; **Upgrading ****llvm**  
> **17.0.5 -&gt; 18.1.6 **  
> ==&gt; **Installing dependencies for llvm: ****mpdecimal****, ****ca-certificates****, ****openssl@3****, ****readline****, ****sqlite****, ****xz****, ****python@3.12****, ****z3** **and ****zstd**  
> ==&gt; **Installing llvm dependency: ****mpdecimal**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/mpdecimal/manifests/4.0.0-1>**  
> Already downloaded: /Users/kjell-olovhogdal/Library/Caches/Homebrew/downloads/7b63c3b34bee402290af49fac829a6682ab45ea5c9258b6fe03b590a03a4c4a9--mpdecimal-4.0.0-1.bottle_manifest.json  
> ==&gt; **Pouring mpdecimal--4.0.0.monterey.bottle.1.tar.gz**  
> 🍺 /usr/local/Cellar/mpdecimal/4.0.0: 22 files, 603.5KB  
> ==&gt; **Installing llvm dependency: ****ca-certificates**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/ca-certificates/manifests/2024-03-11>**  
> Already downloaded: /Users/kjell-olovhogdal/Library/Caches/Homebrew/downloads/c431e0186df2ccc2ea942b34a3c26c2cebebec8e07ad6abdae48447a52c5f506--ca-certificates-2024-03-11.bottle_manifest.json  
> ==&gt; **Pouring ca-certificates--2024-03-11.all.bottle.tar.gz**  
> ==&gt; **Regenerating CA certificate bundle from keychain, this may take a while...**  
> 🍺 /usr/local/Cellar/ca-certificates/2024-03-11: 4 files, 232.3KB  
> ==&gt; **Installing llvm dependency: ****openssl@3**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/openssl/3/manifests/3.3.0-1>**  
> Already downloaded: /[Users/kjell-olovhogdal/Library/Caches/Homebrew/downloads/cd7e4cb72da375d51619d8c60fb91a70696e352edb515631b5751d05342e471d--openssl@3-3.3.0-1.bottle_manifest.json](mailto:Users/kjell-olovhogdal/Library/Caches/Homebrew/downloads/cd7e4cb72da375d51619d8c60fb91a70696e352edb515631b5751d05342e471d--openssl@3-3.3.0-1.bottle_manifest.json)  
> ==&gt; **Pouring openssl@3--3.3.0.monterey.bottle.1.tar.gz**  
> 🍺 /usr/local/Cellar/openssl@3/3.3.0: 6,977 files, 33.0MB  
> ==&gt; **Installing llvm dependency: ****readline**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/readline/manifests/8.2.10>**  
> Already downloaded: /Users/kjell-olovhogdal/Library/Caches/Homebrew/downloads/4ddd52803319828799f1932d4c7fa8d11c667049b20a56341c0c19246a1be93b--readline-8.2.10.bottle_manifest.json  
> ==&gt; **Pouring readline--8.2.10.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/readline/8.2.10: 51 files, 1.7MB  
> ==&gt; **Installing llvm dependency: ****sqlite**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/sqlite/manifests/3.46.0>**  
> Already downloaded: /Users/kjell-olovhogdal/Library/Caches/Homebrew/downloads/7d6bff4676b4f32a64f5d9436491b1eedb27a559ef4ff63aaaa62834a981bcd0--sqlite-3.46.0.bottle_manifest.json  
> ==&gt; **Pouring sqlite--3.46.0.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/sqlite/3.46.0: 12 files, 4.8MB  
> ==&gt; **Installing llvm dependency: ****xz**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/xz/manifests/5.4.6>**  
> Already downloaded: /Users/kjell-olovhogdal/Library/Caches/Homebrew/downloads/b2cc4077807c100af6e0253f51d186f187ff55165638cbe3a4aa16d1c4762660--xz-5.4.6.bottle_manifest.json  
> ==&gt; **Pouring xz--5.4.6.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/xz/5.4.6: 164 files, 2.6MB  
> ==&gt; **Installing llvm dependency: ****python@3.12**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/python/3.12/manifests/3.12.3>**  
> Already downloaded: /[Users/kjell-olovhogdal/Library/Caches/Homebrew/downloads/5065c4d76c933aad4e13bd77c1bf37f0afe78f4608261edd170e331cb36c8a0d--python@3.12-3.12.3.bottle_manifest.json](mailto:Users/kjell-olovhogdal/Library/Caches/Homebrew/downloads/5065c4d76c933aad4e13bd77c1bf37f0afe78f4608261edd170e331cb36c8a0d--python@3.12-3.12.3.bottle_manifest.json)  
> ==&gt; **Pouring python@3.12--3.12.3.monterey.bottle.tar.gz**  
> Warning: These files were **overwritten** during the \`brew link\` step:  
> **/usr/local/bin/2to3**  
> **/usr/local/bin/idle3**  
> **/usr/local/bin/pydoc3**  
> **/usr/local/bin/python3**  
> **/usr/local/bin/python3-config**  
> **/usr/local/share/man/man1/python3.1**  
> **/usr/local/lib/pkgconfig/python3-embed.pc**  
> **/usr/local/lib/pkgconfig/python3.pc**  
> **/usr/local/Frameworks/Python.framework/Headers**  
> **/usr/local/Frameworks/Python.framework/Python**  
> **/usr/local/Frameworks/Python.framework/Resources**  
> **/usr/local/Frameworks/Python.framework/Versions/Current**

> **They have been backed up to: /Users/kjell-olovhogdal/Library/Caches/Homebrew/Backup**  
> ==&gt; **/usr/local/Cellar/python@3.12/3.12.3/bin/python3.12 -Im ensurepip**  
> ==&gt; **/usr/local/Cellar/python@3.12/3.12.3/bin/python3.12 -Im pip install -v --no-index --upgrade --isolated --target=/usr/local/lib/python3.12/site-packages /usr/local/Cellar/python@3.12/3.12.3/Frameworks/Python.framework/Versions/3.12/lib/python3.12/ensurepip/_bundled/pip-24.0-py3-none-any.whl /usr/local/Cellar/python@3.12/3.12.3/libexec/wheel-0.43.0-py3-none-an**  
> ==&gt; **Summary**  
> 🍺 /usr/local/Cellar/python@3.12/3.12.3: 3,270 files, 64MB  
> ==&gt; **Installing llvm dependency: ****z3**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/z3/manifests/4.13.0>**  
> Already downloaded: /Users/kjell-olovhogdal/Library/Caches/Homebrew/downloads/f76733dc8564492bde6da5ddd68bf485a259b09d276de374047a4600ed52edff--z3-4.13.0.bottle_manifest.json  
> ==&gt; **Pouring z3--4.13.0.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/z3/4.13.0: 120 files, 32.4MB  
> ==&gt; **Installing llvm dependency: ****zstd**  
> ==&gt; **Downloading <https://ghcr.io/v2/homebrew/core/zstd/manifests/1.5.6>**  
> Already downloaded: /Users/kjell-olovhogdal/Library/Caches/Homebrew/downloads/29403e0df5404d8aeca0e750ac135ec9ef44fc5eeb6df69170ed602acabf0ffb--zstd-1.5.6.bottle_manifest.json  
> ==&gt; **Pouring zstd--1.5.6.monterey.bottle.tar.gz**  
> 🍺 /usr/local/Cellar/zstd/1.5.6: 32 files, 2.6MB  
> ==&gt; **Installing ****llvm**  
> ==&gt; **Pouring llvm--18.1.6.monterey.bottle.tar.gz**  
> ==&gt; **Caveats**  
> To use the bundled libc++ please add the following LDFLAGS:  
> LDFLAGS="-L/usr/local/opt/llvm/lib/c++ -Wl,-rpath,/usr/local/opt/llvm/lib/c++"

> llvm is keg-only, which means it was not symlinked into /usr/local,  
> because macOS already provides this software and installing another version in  
> parallel can cause all kinds of trouble.

> If you need to have llvm first in your PATH, run:  
> echo 'export PATH="/usr/local/opt/llvm/bin:$PATH"' &gt;&gt; ~/.zshrc

> For compilers to find llvm you may need to set:  
> export LDFLAGS="-L/usr/local/opt/llvm/lib"  
> export CPPFLAGS="-I/usr/local/opt/llvm/include"  
> ==&gt; **Summary**  
> **🍺 /usr/local/Cellar/llvm/18.1.6: 7,722 files, 1.9GB**

> ==&gt; **Running \`brew cleanup llvm\`...**  
> Disable this behaviour by setting HOMEBREW_NO_INSTALL_CLEANUP.  
> Hide these hints with HOMEBREW_NO_ENV_HINTS (see \`man brew\`).  
> Removing: /usr/local/Cellar/llvm/17.0.5... (7,207 files, 1.7GB)  
> Error: Could not get runtime dependencies from /usr/local/opt/pyside2/.brew/pyside2.rb!  
> Error: No available formula with the name "freecad/freecad/shiboken2@5.15.2". Did you mean freecad/freecad/shiboken2@5.15.5, freecad/freecad/shiboken2@5.15.11, freecad/freecad/shiboken2@5.15.11_py310 or freecad/freecad/pyside2@5.15.5?  
> kjell-olovhogdal@Kjell-Olovs-Mac-Pro cratchit %

...

{% endraw %}
