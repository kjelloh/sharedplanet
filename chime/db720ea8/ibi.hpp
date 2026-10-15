//
//  ibi.hpp
//  ibi
//
//  Created by Kjell-Olov Högdahl on 2016-08-18.
//  Copyright © 2016 Kjell-Olov Högdahl. All rights reserved.
//

#ifndef ibi_hpp
#define ibi_hpp

#include <vector>
#include <boost/variant.hpp>
#include <boost/iterator/zip_iterator.hpp>
#include <boost/optional.hpp>

namespace ibi {

    namespace detail {
        template <typename N>
        class Path {
        private:
            using _Key = N;
            using _Container = std::vector<_Key>;
        public:
            using Key = _Key;
            using iterator = typename _Container::iterator;
            using const_iterator = typename _Container::const_iterator;
            Path() = default;
            Path(const Path& other) = default;
            Path(Path&& other) = default;
            Path& operator=(const Path& other) = default;
            Path(std::initializer_list<N> vars) : m_container(vars) {}
            
            Path<N>& push_back(const Key& key) {m_container.push_back(key); return *this;}
            
            iterator begin() {return m_container.begin();}
            iterator end() {return m_container.end();}
            const_iterator begin() const {return m_container.begin();}
            const_iterator end() const {return m_container.end();}
            
        private:
            std::vector<N> m_container;
        };
        
        template <typename C, typename P>
        class Selector {
        private:
            boost::optional<C> m_result;
        public:
            Selector(const C& c) : m_result(c) {}
            
            // C must be Read Iteratable
            boost::optional<C> operator()(const P& p) {
                for (auto key : p) {
                    if (!m_result) break;
                    auto i = std::find(std::begin(m_result), std::end(m_result),[&key](const C& c){return c == key;});
                    m_result = (i != std::end(m_result))? *i : boost::optional<C>();
                }
                return m_result;
            }
        };
        
    }

    template <typename N>
    using Path = detail::Path<N>;
    
    template <typename C, typename P>
    using Selector = detail::Selector<C, P>;
    
    template <typename _Key1, typename _Key2>
    class ZippedPaths {
    private:
        using _Key = boost::tuple<_Key1,_Key2>;
        using _Path1 = Path<_Key1>;
        using _Path2 = Path<_Key2>;
        using _IteratorTuple = boost::tuple<typename _Path1::const_iterator,typename _Path2::const_iterator>;
        _Path1 m_path1;
        _Path2 m_path2;
        // Constructor helper
        _Path1 keyes1(std::initializer_list<_Key> keyes) {
            _Path1 result;
            for (auto key : keyes) {
                // Rabbit Hole: key.get<0>() does not compile (needs keyword template to access type dependent member template get<>
                result.push_back(key.template get<0>());
            }
            // std::for_each(keyes.begin(), keyes.end(),[&result](const _Key& key){result.push_back(key.template get<0>());});
            return result;
        }
        // Constructor helper
        _Path2 keyes2(std::initializer_list<_Key> keyes) {
            _Path2 result;
            for (auto key : keyes) {
                result.push_back(key.template get<1>());
            }
            // std::for_each(keyes.begin(), keyes.end(),[&result](const _Key& key){result.push_back(key.template get<0>());});
            return result;
        }
    public:
        using iterator = boost::zip_iterator<_IteratorTuple>;
        iterator begin() {return boost::make_zip_iterator(boost::make_tuple(m_path1.begin(),m_path2.begin()));}
        iterator end() {return boost::make_zip_iterator(boost::make_tuple(m_path1.end(),m_path2.end()));}
        
        ZippedPaths() = default;
        ZippedPaths(const ZippedPaths& other) = default;
        ZippedPaths& operator=(const ZippedPaths& other) = default;
        
        ZippedPaths(_Path1&& p1, _Path2&& p2) : m_path1(std::move(p1)), m_path2(std::move(p2)) {}
        ZippedPaths(std::initializer_list<_Key> keyes) : ZippedPaths(keyes1(keyes), keyes2(keyes)) {}
    };
    
    template <typename P1, typename P2>
    class StackedPaths {
    private:
        P1 m_path1;
        P2 m_path2;
    public:
        // begin() and end() returns iterator to variant<P1::iterator, P2::iterator>
        
        template <typename C>
        class Selector /* : public boost::static_visitor<C&> */
        {
        public:
            /* std::optional?*/ C& operator()(C& c, typename P1::Key key) {
                return c; // dummy
            }
            
            C& operator()(C& c,typename P2::Key key) {
                return c; // dummy;
            }
        };
        
    };

    
    
    namespace test {
        void do_test();
    }
        
}

#endif /* ibi_hpp */
