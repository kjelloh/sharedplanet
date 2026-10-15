# Todo: Consider to document installation of Electron development and run-time environment on my different machines?

```#6e60f6a4``` *As of 2017-02-05 19:12*

[mail plain/text](mail.txt)

{% raw %}
Consider it to be a good idea to save documentation on how to install the Electron Environment on my different OS:es and machines?

==&gt; Also see ”[Todo: Consider to document installation of Node.js and accompanying npm package manager to by different computers?](../9d0e6ac8/chime.md)”

1) The Electron Environment seems to be available through the Example package available here (<http://electron.atom.io>)?

==&gt; It seems the download (<https://electron-api-demos.githubapp.com/updates/electron-api-demos-mac.zip>) results in an executable aplication?

![](<Electron API Demos App.tiff>)

==&gt; I Installed Node.js and npm package manager (See ”Todo: Consider to document installation of Node.js and accompanying npm package manager to by different computers?”)

==&gt; Then I cloned the Electron Qick Start from Github as instructed.

==&gt; It seems to install electron to ”/Users/kjell-olovhogdahl/Documents/GitHub/electron/electron-quick-start/node_modules/electron” - **\*sigh\* !!**

> kjell-olov-hogdahls-macbook-pro:~ kjell-olovhogdahl$ pwd  
> /Users/kjell-olovhogdahl  
> kjell-olov-hogdahls-macbook-pro:Documents kjell-olovhogdahl$ cd GitHub/  
> kjell-olov-hogdahls-macbook-pro:GitHub kjell-olovhogdahl$ ls  
> cryptopp  
> kjell-olov-hogdahls-macbook-pro:GitHub kjell-olovhogdahl$ mkdir electron  
> kjell-olov-hogdahls-macbook-pro:GitHub kjell-olovhogdahl$ cd electron  
> kjell-olov-hogdahls-macbook-pro:electron kjell-olovhogdahl$ git clone <https://github.com/electron/electron-quick-start>  
> Cloning into 'electron-quick-start'...  
> remote: Counting objects: 231, done.  
> remote: Total 231 (delta 0), reused 0 (delta 0), pack-reused 231  
> Receiving objects: 100% (231/231), 38.35 KiB | 0 bytes/s, done.  
> Resolving deltas: 100% (105/105), done.  
> kjell-olov-hogdahls-macbook-pro:electron kjell-olovhogdahl$ ls  
> electron-quick-start  
> kjell-olov-hogdahls-macbook-pro:electron kjell-olovhogdahl$ cd electron-quick-start/  
> kjell-olov-hogdahls-macbook-pro:electron-quick-start kjell-olovhogdahl$ npm install && npm start

> &gt; electron@1.4.15 postinstall /Users/kjell-olovhogdahl/Documents/GitHub/electron/electron-quick-start/node_modules/electron  
> &gt; node install.js

> electron-quick-start@1.0.0 /Users/kjell-olovhogdahl/Documents/GitHub/electron/electron-quick-start  
> └─┬ electron@1.4.15  
> ├─┬ electron-download@3.3.0  
> │ ├─┬ debug@2.6.0  
> │ │ └── ms@0.7.2  
> │ ├─┬ fs-extra@0.30.0  
> │ │ ├── graceful-fs@4.1.11  
> │ │ ├── jsonfile@2.4.0  
> │ │ ├── klaw@1.3.1  
> │ │ ├── path-is-absolute@1.0.1  
> │ │ └─┬ rimraf@2.5.4  
> │ │ └─┬ glob@7.1.1  
> │ │ ├── fs.realpath@1.0.0  
> │ │ ├─┬ inflight@1.0.6  
> │ │ │ └── wrappy@1.0.2  
> │ │ ├─┬ minimatch@3.0.3  
> │ │ │ └─┬ brace-expansion@1.1.6  
> │ │ │ ├── balanced-match@0.4.2  
> │ │ │ └── concat-map@0.0.1  
> │ │ └── once@1.4.0  
> │ ├── home-path@1.0.3  
> │ ├── minimist@1.2.0  
> │ ├─┬ nugget@2.0.1  
> │ │ ├─┬ pretty-bytes@1.0.4  
> │ │ │ ├── get-stdin@4.0.1  
> │ │ │ └─┬ meow@3.7.0  
> │ │ │ ├─┬ camelcase-keys@2.1.0  
> │ │ │ │ └── camelcase@2.1.1  
> │ │ │ ├── decamelize@1.2.0  
> │ │ │ ├─┬ loud-rejection@1.6.0  
> │ │ │ │ ├─┬ currently-unhandled@0.4.1  
> │ │ │ │ │ └── array-find-index@1.0.2  
> │ │ │ │ └── signal-exit@3.0.2  
> │ │ │ ├── map-obj@1.0.1  
> │ │ │ ├─┬ normalize-package-data@2.3.5  
> │ │ │ │ ├── hosted-git-info@2.1.5  
> │ │ │ │ ├─┬ is-builtin-module@1.0.0  
> │ │ │ │ │ └── builtin-modules@1.1.1  
> │ │ │ │ └─┬ validate-npm-package-license@3.0.1  
> │ │ │ │ ├─┬ spdx-correct@1.0.2  
> │ │ │ │ │ └── spdx-license-ids@1.2.2  
> │ │ │ │ └── spdx-expression-parse@1.0.4  
> │ │ │ ├── object-assign@4.1.1  
> │ │ │ ├─┬ read-pkg-up@1.0.1  
> │ │ │ │ ├── find-up@1.1.2  
> │ │ │ │ └─┬ read-pkg@1.1.0  
> │ │ │ │ ├─┬ load-json-file@1.1.0  
> │ │ │ │ │ ├─┬ parse-json@2.2.0  
> │ │ │ │ │ │ └─┬ error-ex@1.3.0  
> │ │ │ │ │ │ └── is-arrayish@0.2.1  
> │ │ │ │ │ ├── pify@2.3.0  
> │ │ │ │ │ └─┬ strip-bom@2.0.0  
> │ │ │ │ │ └── is-utf8@0.2.1  
> │ │ │ │ └── path-type@1.1.0  
> │ │ │ ├─┬ redent@1.0.0  
> │ │ │ │ ├─┬ indent-string@2.1.0  
> │ │ │ │ │ └─┬ repeating@2.0.1  
> │ │ │ │ │ └── is-finite@1.0.2  
> │ │ │ │ └── strip-indent@1.0.1  
> │ │ │ └── trim-newlines@1.0.0  
> │ │ ├─┬ progress-stream@1.2.0  
> │ │ │ ├── speedometer@0.1.4  
> │ │ │ └─┬ through2@0.2.3  
> │ │ │ ├─┬ readable-stream@1.1.14  
> │ │ │ │ └── isarray@0.0.1  
> │ │ │ └─┬ xtend@2.1.2  
> │ │ │ └── object-keys@0.4.0  
> │ │ ├─┬ request@2.79.0  
> │ │ │ ├── aws-sign2@0.6.0  
> │ │ │ ├── aws4@1.5.0  
> │ │ │ ├── caseless@0.11.0  
> │ │ │ ├─┬ combined-stream@1.0.5  
> │ │ │ │ └── delayed-stream@1.0.0  
> │ │ │ ├── extend@3.0.0  
> │ │ │ ├── forever-agent@0.6.1  
> │ │ │ ├─┬ form-data@2.1.2  
> │ │ │ │ └── asynckit@0.4.0  
> │ │ │ ├─┬ har-validator@2.0.6  
> │ │ │ │ ├─┬ chalk@1.1.3  
> │ │ │ │ │ ├── ansi-styles@2.2.1  
> │ │ │ │ │ ├── escape-string-regexp@1.0.5  
> │ │ │ │ │ ├── has-ansi@2.0.0  
> │ │ │ │ │ └── supports-color@2.0.0  
> │ │ │ │ ├─┬ commander@2.9.0  
> │ │ │ │ │ └── graceful-readlink@1.0.1  
> │ │ │ │ └─┬ is-my-json-valid@2.15.0  
> │ │ │ │ ├── generate-function@2.0.0  
> │ │ │ │ ├─┬ generate-object-property@1.2.0  
> │ │ │ │ │ └── is-property@1.0.2  
> │ │ │ │ ├── jsonpointer@4.0.1  
> │ │ │ │ └── xtend@4.0.1  
> │ │ │ ├─┬ hawk@3.1.3  
> │ │ │ │ ├── boom@2.10.1  
> │ │ │ │ ├── cryptiles@2.0.5  
> │ │ │ │ ├── hoek@2.16.3  
> │ │ │ │ └── sntp@1.0.9  
> │ │ │ ├─┬ http-signature@1.1.1  
> │ │ │ │ ├── assert-plus@0.2.0  
> │ │ │ │ ├─┬ jsprim@1.3.1  
> │ │ │ │ │ ├── extsprintf@1.0.2  
> │ │ │ │ │ ├── json-schema@0.2.3  
> │ │ │ │ │ └── verror@1.3.6  
> │ │ │ │ └─┬ sshpk@1.10.2  
> │ │ │ │ ├── asn1@0.2.3  
> │ │ │ │ ├── assert-plus@1.0.0  
> │ │ │ │ ├── bcrypt-pbkdf@1.0.1  
> │ │ │ │ ├─┬ dashdash@1.14.1  
> │ │ │ │ │ └── assert-plus@1.0.0  
> │ │ │ │ ├── ecc-jsbn@0.1.1  
> │ │ │ │ ├─┬ getpass@0.1.6  
> │ │ │ │ │ └── assert-plus@1.0.0  
> │ │ │ │ ├── jodid25519@1.0.2  
> │ │ │ │ ├── jsbn@0.1.0  
> │ │ │ │ └── tweetnacl@0.14.5  
> │ │ │ ├── is-typedarray@1.0.0  
> │ │ │ ├── isstream@0.1.2  
> │ │ │ ├── json-stringify-safe@5.0.1  
> │ │ │ ├─┬ mime-types@2.1.14  
> │ │ │ │ └── mime-db@1.26.0  
> │ │ │ ├── oauth-sign@0.8.2  
> │ │ │ ├── qs@6.3.0  
> │ │ │ ├── stringstream@0.0.5  
> │ │ │ ├─┬ tough-cookie@2.3.2  
> │ │ │ │ └── punycode@1.4.1  
> │ │ │ ├── tunnel-agent@0.4.3  
> │ │ │ └── uuid@3.0.1  
> │ │ ├─┬ single-line-log@1.1.2  
> │ │ │ └─┬ string-width@1.0.2  
> │ │ │ ├── code-point-at@1.1.0  
> │ │ │ ├─┬ is-fullwidth-code-point@1.0.0  
> │ │ │ │ └── number-is-nan@1.0.1  
> │ │ │ └─┬ strip-ansi@3.0.1  
> │ │ │ └── ansi-regex@2.1.1  
> │ │ └── throttleit@0.0.2  
> │ ├─┬ path-exists@2.1.0  
> │ │ └─┬ pinkie-promise@2.0.1  
> │ │ └── pinkie@2.0.4  
> │ ├─┬ rc@1.1.6  
> │ │ ├── deep-extend@0.4.1  
> │ │ ├── ini@1.3.4  
> │ │ └── strip-json-comments@1.0.4  
> │ ├── semver@5.3.0  
> │ └─┬ sumchecker@1.3.0  
> │ └── es6-promise@4.0.5  
> └─┬ extract-zip@1.6.0  
> ├─┬ concat-stream@1.5.0  
> │ ├── inherits@2.0.3  
> │ ├─┬ readable-stream@2.0.6  
> │ │ ├── core-util-is@1.0.2  
> │ │ ├── isarray@1.0.0  
> │ │ ├── process-nextick-args@1.0.7  
> │ │ ├── string_decoder@0.10.31  
> │ │ └── util-deprecate@1.0.2  
> │ └── typedarray@0.0.6  
> ├── debug@0.7.4  
> ├─┬ mkdirp@0.5.0  
> │ └── minimist@0.0.8  
> └─┬ yauzl@2.4.1  
> └─┬ fd-slicer@1.0.1  
> └── pend@1.2.0

> &gt; electron-quick-start@1.0.0 start /Users/kjell-olovhogdahl/Documents/GitHub/electron/electron-quick-start  
> &gt; electron .

**==&gt; Consider to find a way to install electron framework to a more neutral and permanent location?**

**WE ARE HERE...**

==&gt; Anyhow - An example electron application starts ok!

![](<Electron Example - Hello World Application.tiff>)

==&gt; It seems to provide means to edit the code and see the result - all within itself? :)

2) Consider to update this documentation for how to install Electron to other OS:es and platforms?

…

…

Consider to update this documentation when required for updates and installations on other platforms and machines?

...

{% endraw %}
