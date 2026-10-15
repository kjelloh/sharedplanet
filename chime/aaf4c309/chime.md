# Todo: Consider The Elm Architecture (TEA) based Github project "TeaGameLibrary"?

```#aaf4c309``` *As of 2025-02-20 11:50*

[mail plain/text](mail.txt)

{% raw %}
I want to find a suitable implementation of TEA for C++ and studying Github projects may give some insights?

1) Consider the Github Project "TeaGameLibrary" (<https://github.com/elipmoc/TeaGameLibrary/tree/master> )?

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub % git clone https://github.com/elipmoc/TeaGameLibrary.git

> Cloning into 'TeaGameLibrary'...

> remote: Enumerating objects: 989, done.

> remote: Counting objects: 100% (365/365), done.

> remote: Compressing objects: 100% (218/218), done.

> remote: Total 989 (delta 190), reused 287 (delta 131), pack-reused 624 (from 1)

> Receiving objects: 100% (989/989), 7.74 MiB | 3.78 MiB/s, done.

> Resolving deltas: 100% (533/533), done.

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub % cd TeaGameLibrary

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/TeaGameLibrary % tree

> .

> ├── CODE_OF_CONDUCT.md

> ├── ExampleGame1

> │ ├── ExampleGame1.vcxproj

> │ ├── ExampleGame1.vcxproj.filters

> │ └── Main.cpp

> ├── ExampleGame2

> │ ├── Assets

> │ │ ├── Farback01.png

> │ │ ├── Farback02.png

> │ │ ├── Ship01.png

> │ │ ├── Ship02.png

> │ │ ├── Ship03.png

> │ │ ├── Ship04.png

> │ │ └── Stars.png

> │ ├── BackGround.cpp

> │ ├── CommonMsg.hpp

> │ ├── ExampleGame2.vcxproj

> │ ├── ExampleGame2.vcxproj.filters

> │ ├── Main.cpp

> │ ├── Ship.cpp

> │ └── test.png

> ├── External

> │ ├── BUGS.txt

> │ ├── COPYING.txt

> │ ├── README-SDL.txt

> │ ├── README.txt

> │ ├── WhatsNew.txt

> │ ├── include

> │ │ └── SDL

> │ │ ├── SDL.h

> │ │ ├── SDL_assert.h

> │ │ ├── SDL_atomic.h

> │ │ ├── SDL_audio.h

> │ │ ├── SDL_bits.h

> │ │ ├── SDL_blendmode.h

> │ │ ├── SDL_clipboard.h

> │ │ ├── SDL_config.h

> │ │ ├── SDL_config.h.cmake

> │ │ ├── SDL_config.h.in

> │ │ ├── SDL_config_android.h

> │ │ ├── SDL_config_iphoneos.h

> │ │ ├── SDL_config_macosx.h

> │ │ ├── SDL_config_minimal.h

> │ │ ├── SDL_config_os2.h

> │ │ ├── SDL_config_pandora.h

> │ │ ├── SDL_config_psp.h

> │ │ ├── SDL_config_windows.h

> │ │ ├── SDL_config_winrt.h

> │ │ ├── SDL_config_wiz.h

> │ │ ├── SDL_copying.h

> │ │ ├── SDL_cpuinfo.h

> │ │ ├── SDL_egl.h

> │ │ ├── SDL_endian.h

> │ │ ├── SDL_error.h

> │ │ ├── SDL_events.h

> │ │ ├── SDL_filesystem.h

> │ │ ├── SDL_gamecontroller.h

> │ │ ├── SDL_gesture.h

> │ │ ├── SDL_haptic.h

> │ │ ├── SDL_hints.h

> │ │ ├── SDL_image.h

> │ │ ├── SDL_joystick.h

> │ │ ├── SDL_keyboard.h

> │ │ ├── SDL_keycode.h

> │ │ ├── SDL_loadso.h

> │ │ ├── SDL_log.h

> │ │ ├── SDL_main.h

> │ │ ├── SDL_messagebox.h

> │ │ ├── SDL_mouse.h

> │ │ ├── SDL_mutex.h

> │ │ ├── SDL_name.h

> │ │ ├── SDL_opengl.h

> │ │ ├── SDL_opengl_glext.h

> │ │ ├── SDL_opengles.h

> │ │ ├── SDL_opengles2.h

> │ │ ├── SDL_opengles2_gl2.h

> │ │ ├── SDL_opengles2_gl2ext.h

> │ │ ├── SDL_opengles2_gl2platform.h

> │ │ ├── SDL_opengles2_khrplatform.h

> │ │ ├── SDL_pixels.h

> │ │ ├── SDL_platform.h

> │ │ ├── SDL_power.h

> │ │ ├── SDL_quit.h

> │ │ ├── SDL_rect.h

> │ │ ├── SDL_render.h

> │ │ ├── SDL_revision.h

> │ │ ├── SDL_rwops.h

> │ │ ├── SDL_scancode.h

> │ │ ├── SDL_sensor.h

> │ │ ├── SDL_shape.h

> │ │ ├── SDL_stdinc.h

> │ │ ├── SDL_surface.h

> │ │ ├── SDL_system.h

> │ │ ├── SDL_syswm.h

> │ │ ├── SDL_test.h

> │ │ ├── SDL_test_assert.h

> │ │ ├── SDL_test_common.h

> │ │ ├── SDL_test_compare.h

> │ │ ├── SDL_test_crc32.h

> │ │ ├── SDL_test_font.h

> │ │ ├── SDL_test_fuzzer.h

> │ │ ├── SDL_test_harness.h

> │ │ ├── SDL_test_images.h

> │ │ ├── SDL_test_log.h

> │ │ ├── SDL_test_md5.h

> │ │ ├── SDL_test_memory.h

> │ │ ├── SDL_test_random.h

> │ │ ├── SDL_thread.h

> │ │ ├── SDL_timer.h

> │ │ ├── SDL_touch.h

> │ │ ├── SDL_types.h

> │ │ ├── SDL_version.h

> │ │ ├── SDL_video.h

> │ │ ├── SDL_vulkan.h

> │ │ ├── begin_code.h

> │ │ └── close_code.h

> │ └── lib

> │ ├── Debug

> │ │ ├── LICENSE.jpeg.txt

> │ │ ├── LICENSE.png.txt

> │ │ ├── LICENSE.tiff.txt

> │ │ ├── LICENSE.webp.txt

> │ │ ├── LICENSE.zlib.txt

> │ │ ├── SDL2-static.lib

> │ │ ├── SDL2_image.lib

> │ │ └── SDL2main.lib

> │ └── Release

> │ ├── LICENSE.jpeg.txt

> │ ├── LICENSE.png.txt

> │ ├── LICENSE.tiff.txt

> │ ├── LICENSE.webp.txt

> │ ├── LICENSE.zlib.txt

> │ ├── SDL2-static.lib

> │ ├── SDL2_image.lib

> │ └── SDL2main.lib

> ├── LICENSE

> ├── README.md

> ├── TeaGameLib

> │ ├── TeaGameLib.vcxproj

> │ ├── TeaGameLib.vcxproj.filters

> │ ├── include

> │ │ ├── Algorithm.hpp

> │ │ ├── Color.hpp

> │ │ ├── GameWorld

> │ │ │ └── GameWorldData.hpp

> │ │ ├── GameWorld.hpp

> │ │ ├── Input

> │ │ │ ├── KeyCode.hpp

> │ │ │ └── KeyStates.hpp

> │ │ ├── Input.hpp

> │ │ ├── InternalGameLib

> │ │ │ ├── DrawService.hpp

> │ │ │ ├── FpsWaitTicks.hpp

> │ │ │ ├── InternalGameLib.hpp

> │ │ │ ├── InternalGameLibHandlers.hpp

> │ │ │ └── Resource

> │ │ │ ├── ResourceLoader.hpp

> │ │ │ └── TextureResource.hpp

> │ │ ├── Math

> │ │ │ └── Vector2D.hpp

> │ │ ├── Platform

> │ │ │ └── Effect.hpp

> │ │ ├── ResourceManager.hpp

> │ │ ├── UtilModel

> │ │ │ └── AnimSpriteModel.hpp

> │ │ ├── Variant.hpp

> │ │ ├── View.hpp

> │ │ ├── Window

> │ │ │ ├── App

> │ │ │ │ ├── Actor.hpp

> │ │ │ │ ├── EffectMsgQueue.hpp

> │ │ │ │ ├── EffectMsgQueueFactory

> │ │ │ │ │ └── CreateCommonEffectMsgQueue.hpp

> │ │ │ │ ├── UpdateData.hpp

> │ │ │ │ └── WindowData.hpp

> │ │ │ └── App.hpp

> │ │ ├── WindowEvent

> │ │ │ └── EventStates.hpp

> │ │ └── WindowEvent.hpp

> │ └── src

> │ ├── InternalGameLib

> │ │ ├── Interface

> │ │ │ ├── DrawPrimitive.hpp

> │ │ │ ├── DrawSprite.hpp

> │ │ │ ├── GameInitializer.hpp

> │ │ │ └── GameShutDown.hpp

> │ │ └── SDLImpl

> │ │ ├── Resource

> │ │ │ ├── SDLResourceLoader.cpp

> │ │ │ ├── SDLTextureResource.cpp

> │ │ │ └── SDLTextureResourceImpl.hpp

> │ │ ├── SDLDrawPrimitive.cpp

> │ │ ├── SDLDrawService.cpp

> │ │ ├── SDLDrawSprite.cpp

> │ │ ├── SDLFpsWaitTicks.cpp

> │ │ ├── SDLGameInitializer.cpp

> │ │ ├── SDLGameLib.cpp

> │ │ ├── SDLGameShutDown.cpp

> │ │ └── SDLHandlers.hpp

> │ ├── View.cpp

> │ └── Window

> │ └── App.cpp

> ├── TeaGameLibrary.sln

> └── developers.md

> 29 directories, 176 files

> kjell-olovhogdahl@MacBook-Pro ~/Documents/GitHub/TeaGameLibrary %



2) Consider the 'teaGameLib::Actor{ Init,Update,Subscription,View }'?

==&gt; It seems it is Actor that aggregates the application init, update, view and subscription functions?

> UpdateData&lt;Model,Msg&gt; InvokeInitFunc()const { return initFunc(); }  
> UpdateData&lt;Model, Msg&gt; InvokeUpdateFunc(Msg msg, Model&& model)const { return updateFunc(msg, std::move(model)); }  
> void InvokeViewFunc(const Model& model, View& view)const { viewFunc(model, view); }  
> Sub&lt;Msg&gt; InvokeSubscriptionFunc(const Model& model)const { return subscriptionFunc(model); }

==&gt; It seems the 'runtime' is in App::Start?

> void Start(StartActor startActor, UpdateMsgFunc updateMsgFunc) {  
> using Msg = std::invoke_result_t&lt;UpdateMsgFunc, float&gt;;  
> std::queue&lt;Msg&gt; queue;  
> EffectMsgQueue&lt;Msg&gt; effectMsgQueue = CreateCommonEffectMsgQueue&lt;Msg&gt;(queue);  
> int ticksCount = 0;  
> auto &#91;initCmd, model&#93; = startActor.InvokeInitFunc();  
> initCmd.InvokeRunFunc(effectMsgQueue);  
> while (gameWorldData.GetIsRunning()) {  
> UpdateInput();  
> startActor.InvokeSubscriptionFunc(model).InvokeRunFunc(effectMsgQueue);  
> float deltaTime = FpsWaitTicks(ticksCount);  
> effectMsgQueue.InQueueMsg(updateMsgFunc(deltaTime));

> model =  
> UpdateMsgQueue(queue, std::move(model), startActor, effectMsgQueue);

> DrawService::Draw(  
> internalGameLibHandlersPtr,  
> gameWorldData.GetBackGroundColor(),  
> &#91;&&#93;() {startActor.InvokeViewFunc(model, view); }  
> );  
> }  
> }

==&gt; How is Msg, Cmd and Sub implemented?

> *In 'ExampleGame1' main() we see:*

> //Msg  
> using Msg = tea::Variant&lt;MsgType::AddY, MsgType::Update, MsgType::End&gt;;

> //Cmd,Subの型省略  
> using Cmd = tea::Cmd&lt;Msg&gt;;  
> using Sub = tea::Sub&lt;Msg&gt;;

> *In TeaGameLib/include/variant.hpp*

> template&lt;typename ...Args&gt;

> using Variant = std::variant&lt;Args...&gt;;

> *In TeaGameLib/include/platform/Effect.hpp*

> template&lt;typename Msg&gt;  
> using Cmd = Effect&lt;Msg&gt;;

> template&lt;typename Msg&gt;  
> using Sub = Effect&lt;Msg&gt;;

> *...*

...

{% endraw %}
